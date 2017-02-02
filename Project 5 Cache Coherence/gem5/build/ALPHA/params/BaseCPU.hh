#ifndef __PARAMS__BaseCPU__
#define __PARAMS__BaseCPU__

class BaseCPU;

#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/AlphaTLB.hh"
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/System.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/BaseCPU.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "params/AlphaInterrupts.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <vector>
#include "params/Process.hh"
#include <cstddef>
#include "params/AlphaTLB.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/InstTracer.hh"

#include "params/MemObject.hh"

struct BaseCPUParams
    : public MemObjectParams
{
    bool do_statistics_insts;
    unsigned numThreads;
    AlphaISA::TLB * itb;
    bool function_trace;
    bool do_checkpoint_insts;
    Counter max_loads_all_threads;
    Tick clock;
    System * system;
    Tick function_trace_start;
    int cpu_id;
    BaseCPU * checker;
    bool do_quiesce;
    Tick profile;
    bool defer_registration;
    AlphaISA::Interrupts * interrupts;
    Counter max_insts_all_threads;
    Tick phase;
    std::vector< Process * > workload;
    AlphaISA::TLB * dtb;
    Counter max_insts_any_thread;
    Tick progress_interval;
    Counter max_loads_any_thread;
    Trace::InstTracer * tracer;
    unsigned int port_icache_port_connection_count;
    unsigned int port_dcache_port_connection_count;
};

#endif // __PARAMS__BaseCPU__
