
#include "instance.hpp"
#include <flame/interface/log.hpp>
#include <filesystem>
#include <fstream>
#include <dep/json.hpp>
#include "def.hpp"

using namespace std;
using json = nlohmann::json;

namespace flame_rt {
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

        /* required services */
        if(config.find(__CONFIG_KEY_REQUIRED__)!=config.end()){
            //if(config[__CONFIG_KEY_REQUIRED__].find(__CONFIG_KEY_REQUIRED_SERVICE__)!=config[])
        }


        return true;
    }

    void run(){

    }

    void cleanup(){

    }
}