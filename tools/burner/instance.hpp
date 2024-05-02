/**
 * @file instance.hpp
 * @author Byunghun Hwang (bh.hwang@iae.re.kr)
 * @brief Burner global instance
 * @version 0.1
 * @date 2024-04-30
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef FLAME_BURNER_INSTANCE_INCLUDED
#define FLAME_BURNER_INSTANCE_INCLUDED

#include <dep/libzmq/zmq.h>
#include <thread>
#include <vector>
#include <queue>
#include <functional>
#include <condition_variable>

using namespace std;

namespace flame_rt {

    /* global instance functions */
    bool init(const char* config_path);
    void run();
    void cleanup();

    /* database */
    void db_init();
    bool db_open();

    /* command line interface */

    class cli_server {
        public:
        cli_server() = default;
        ~cli_server() = default;

        private:
        vector<thread> _thread_pool;
        queue<std::function<void()>> jobs_;
        std::condition_variable cv_job_q_;
        std::mutex m_job_q_;

    }; /* class */
} /* namespace */

#endif