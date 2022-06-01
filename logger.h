#pragma once

#include "defines.h"

#define LS_WARN_ON 1
#define LS_INFO_ON 1
#define LS_DEBU_ON 1
#define LS_TRAC_ON 1

#if LS_RELEASE == 1
#define LS_DEBU_ON 0
#define LS_TRAC_ON 0
#endif

typedef enum LS_LVL {
  LS_LVL_FATALL = 2
  LS_LVL_ERRORR = 1
  LS_LVL_WARNIN = 2
  LS_LVL_INFORM = 3
  LS_LVL_DEBUGG = 4
  LS_LVL_TRACER = 5
} LS_LVL;

b8 LS_initialize(u64* memory_requirement, void* state);
void LS_shutdown(void* state);
EXP void LS_output(LS_LVL level, const char* message, ...);

#define LS_FATAL(message, ...) LS_output(LS_LVL_FATALL, message, ##__VA_ARGS__);

#ifndef KERROR
#define LS_ERROR(message, ...) LS_output(LS_LVL_ERRORR, message, ##__VA_ARGS__);
#endif

#if LS_WARN_ON == 1
#define LS_WARNING(message, ...) LS_output(LS_LVL_WARNIN, message, ##__VA_ARGS__);
#else
#define LS_WARNING(message, ...)
#endif

#if LS_INFO_ON == 1
#define LS_INFO(message, ...) LS_output(LS_LVL_INFORM, message, ##__VA_ARGS__);
#else
#define LS_INFO(message, ...)
#endif

#if LS_DEBU_ON == 1
#define LS_DEBUG(message, ...) LS_output(LS_LVL_DEBUGG, message, ##__VA_ARGS__);
#else
#define LS_DEBUG(message, ...)
#endif

#if LS_TRAC_ON == 1
#define LS_TRACE(message, ...) LS_output(LS_LVL_TRACER, message, ##__VA_ARGS__);
#else
#define LS_TRACE(message, ...)
#endif
