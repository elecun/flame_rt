/**
 * @file singleton.hpp
 * @author Byunghun Hwang <bh.hwang@iae.re.kr>
 * @brief Singleton pattern design class
 * @version 0.1
 * @date 2024-05-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#ifndef FLAME_RT_CORE_EXTRA_SINGLETON_HPP_INCLUDED
#define FLAME_RT_CORE_EXTRA_SINGLETON_HPP_INCLUDED

#include <utility>

namespace flame_rt::extra {

    template<class _t>
    class singleton {
        public:
        static _t* instance(){
            if(!_instance){
                _instance = new _t();
            }
            return _instance;
        }

        static void terminate() {
            if(_instance){
                delete _instance;
                _instance = nullptr;
            }
        }

        protected:
        singleton() = default;
        ~singleton() = default;
        singleton(const singleton&) = delete;   //for noncopyable
        singleton& operator=(const singleton&) = delete; //for noncopyable

        private:
        static _t* _instance;
    }; /* class*/

    template <class _t> _t* singleton<_t>::_instance = nullptr; //initialize

} /* namespace */

#endif