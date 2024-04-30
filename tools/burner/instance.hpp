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

namespace flame_rt {

    /* global instance functions */
    bool init(const char* config_path);
    void run();
    void cleanup();

    /* database */
    void db_init();
    bool db_open();
    
}

#endif