#ifndef __PARAMS__CheckerCPU__
#define __PARAMS__CheckerCPU__

class CheckerCPU;

#include <cstddef>
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include "base/types.hh"

#include "params/BaseCPU.hh"

struct CheckerCPUParams
    : public BaseCPUParams
{
    bool exitOnError;
    bool updateOnError;
    bool function_trace;
    bool warnOnlyOnLoadError;
    Tick function_trace_start;
};

#endif // __PARAMS__CheckerCPU__
