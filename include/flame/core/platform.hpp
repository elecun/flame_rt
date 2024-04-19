/**
 * @file platform.hpp
 * @author Byunghun Hwang (bh.hwang@iae.re.kr)
 * @brief 
 * @version 0.1
 * @date 2024-04-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef FLAME_CORE_PLATFORM_HPP_INCLUDED
#define FLAME_CORE_PLATFORM_HPP_INCLUDED

#ifdef _WIN32
#  define FLAME_PLATFORM_WINDOWS

#  if defined(_MSVC_TRADITIONAL) && _MSVC_TRADITIONAL
#    error MSVC requires the '/experimental:preprocessor' conformance mode!
#  endif
#elif __APPLE_CC__
#  define FLAME_PLATFORM_MACOS
#else
#  define FLAME_PLATFORM_UNIX
#endif

#if defined(_MSC_VER)
#  define FLAME_COMPILER_MSVC
#elif defined(__clang__)
#  define FLAME_COMPILER_CLANG
#elif defined(__GNUC__)
#  define FLAME_COMPILER_GCC
#elif !defined(FLAME_HAS_SUPPRESSED_UNKNOWN_COMPILER)
#  error Unknown compiler!
#endif

#endif