
#include "instance.hpp"
#include <flame/interface/log.hpp>
#include <filesystem>
#include <fstream>
#include <dep/json.hpp>
#include "def.hpp"
#include "manager.hpp"
#include <dep/libzmq/zmq.hpp>
#include <thread>

using namespace std;
using json = nlohmann::json;

namespace flame_rt {

    /**
     * @brief CLI responding thread
     * 
     * @param context 
     */
    void cli_thread(zmq::context_t* context, int access_port){
        zmq::socket_t socket(*context, zmq::socket_type::rep);
        socket.bind (fmt::format("tcp://*:{}", access_port));

        while (true) {
            zmq::message_t request;
            responder.recv(&request); // 요청 수신

            std::cout << "Received request: " << static_cast<char*>(request.data()) << std::endl;

            // 응답 작성 및 전송
            zmq::message_t reply(5);
            memcpy(reply.data(), "World", 5);
            responder.send(reply);
        }
    }

    /**
     * @brief read configuration file (JSON) & initialize
     * 
     * @param config_path 
     * @return true if success
     * @return false read failed
     */
    bool init(const char* config_path){

        filesystem::path _conf_path(config_path);
        json config;

        try {
            console::info("Config file path(absolute) : {}", filesystem::canonical(_conf_path).string());
            console::info("Parent path : {}", filesystem::canonical(_conf_path).parent_path().string());

            /* file existance check */
            if(!filesystem::exists(_conf_path)){
                console::error("Configuration file does not exist.");
                return false;
            }

            /* read configurations from file*/
            std::ifstream file(_conf_path.string());
            file >> config;
        }
        catch(const json::exception& e){
            console::error("configuration file load failed : {}", e.what());
            return false;
        }
        catch(const std::ifstream::failure& e){
            console::error("configuration file load failed : {}", e.what());
            return false;
        }
        catch(const filesystem::filesystem_error& e){
            console::error("configuration file load failed : {}", e.what());
            return false;
        }

        /* zmq server creation */
        if(config.find(__CONFIG_KEY_ACCESS__)!=config.end()){
            int access_port = config[__CONFIG_KEY_ACCESS__].get<int>();
            zmq::context_t context(1); //io thread = 1
            thread cli_responder(cli_thread, &context, access_port); //responding thread
            console::info("CLI accessiable : {}", access_port);
        }

        /* list-up required bundles */
        // if(config.find(__CONFIG_KEY_REQUIRED__)!=config.end()){
        //     auto config_required = config[__CONFIG_KEY_REQUIRED__];

        //     if(config_required.find(__CONFIG_KEY_REQUIRED_BUNDLE__)!=config_required.end()){
        //         vector<string> required_bundle = config_required[__CONFIG_KEY_REQUIRED_BUNDLE__].get<vector<string>>();
        //         for(string& bundle:required_bundle){
        //             bundle_manager->load(bundle.c_str());
        //             //install(bundle.c_str());
        //         }
        //     }
        // }

        return true;
    }

    void run(){

    }

    void cleanup(){

    }
}