#ifndef __PARAMS__Directory_Controller__
#define __PARAMS__Directory_Controller__

class Directory_Controller;

#include <cstddef>
#include "params/RubyDirectoryMemory.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/RubyMemoryControl.hh"
#include <cstddef>

#include "params/RubyController.hh"

struct Directory_ControllerParams
    : public RubyControllerParams
{
    Directory_Controller * create();
    DirectoryMemory * directory;
    int directory_latency;
    MemoryControl * memBuffer;
    bool send_evictions;
};

#endif // __PARAMS__Directory_Controller__
