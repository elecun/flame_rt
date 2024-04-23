/**
 * @file lifecycle_nonperiodic.cpp
 * @author Byunghun Hwang <bh.hwang@iae.re.kr>
 * @brief Non Periodic Task Component Example
 * @version 0.1
 * @date 2024-04-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */

 #include <flame/flame.hpp>

 using namespace flame;

 namespace example{
    class lifecycle_nonperiodic : public taskImpl<nonPeriodic>{

    }; /* class */
 } /* namespace */