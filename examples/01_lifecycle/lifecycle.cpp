/**
 * @file lifecycle.cpp
 * @author Byunghun Hwang (bh.hwang@iae.re.kr)
 * @brief Life Cycle Task Example
 * @version 0.1
 * @date 2024-04-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

/* Warning */
/*
This example is incompleted example code.
*/

#include <flame/flame.hpp>

using namespace flame;

namespace example {

    class lifecycle final : public TaskImpl<Periodic> {
        public:

        // initialize once before start
        void on_init() override {

        }

        void on_setup() override {

        }

        // running task for every time set up
        void on_loop() override {

        }

        void on_destory() override {

        }

        FLAME_TASK

    };

    FLAME_DECLARE(lifecycle)

}