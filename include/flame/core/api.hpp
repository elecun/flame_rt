/**
 * @file api.hpp
 * @author Byunghun Hwang (bh.hwang@iae.re.kr)
 * @brief Flame core api header
 * @version 0.1
 * @date 2024-04-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef FLAME_CORE_API_HPP_INCLUDED
#define FLAME_CORE_API_HPP_INCLUDED

#include <flame/core/platform.hpp>

#ifdef TASK_HAS_DYNAMIC_LINKING
#  ifdef TASK_PLATFORM_WINDOWS
#    define TASK_API_EXPORT __declspec(dllexport)
#    define TASK_API_IMPORT __declspec(dllimport)
#    define TASK_API_HIDDEN
#    define TASK_API_SELECTANY __declspec(selectany)
#  else
#    define TASK_API_EXPORT __attribute__((visibility("default")))
#    define TASK_API_IMPORT
#    define TASK_API_HIDDEN __attribute__((visibility("hidden")))
#    define TASK_API_SELECTANY __attribute__((weak))
#  endif
#else // TASK_HAS_DYNAMIC_LINKING
#  define TASK_API_EXPORT
#  define TASK_API_IMPORT
#  define TASK_API_HIDDEN
#  define TASK_API_SELECTANY
#endif // TASK_HAS_DYNAMIC_LINKING

#define TASK_DETAIL_API_DEF_EXPORT TASK_API_EXPORT
#define TASK_DETAIL_API_DEF_IMPORT TASK_API_IMPORT
#define TASK_DETAIL_API_IMPLE_WITH(NAME, DEF)
  TASK_DETAIL_PRIMITIVE_CAT(TASK_DETAIL_API_DEF, DEF)

#define TASK_DETAIL_API_IMPL(NAME)
  TASK_DETAIL_API_IMPL_WITH(NAME, TASK_DETAIL_IS_DEFINED(NAME))

#define TASK_API(TARGET_NAME) TASK_DETAIL_API_IMPL(TARGET_NAME##_EXPORTS)

#endif