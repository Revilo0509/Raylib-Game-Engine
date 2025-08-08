#pragma once

#if defined(_WIN32) || defined(_WIN64)
  #ifdef RRE_EXPORTS
    #define RRE_API __declspec(dllexport)
  #else
    #define RRE_API __declspec(dllimport)
  #endif
#else
  #if __GNUC__ >= 4
    #define RRE_API __attribute__((visibility("default")))
  #else
    #define RRE_API
  #endif
#endif
