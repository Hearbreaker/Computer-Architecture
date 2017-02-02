#ifndef __PARAMS__DmaDevice__
#define __PARAMS__DmaDevice__

class DmaDevice;

#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/PioDevice.hh"

struct DmaDeviceParams
    : public PioDeviceParams
{
    Tick min_backoff_delay;
    Tick max_backoff_delay;
    unsigned int port_dma_connection_count;
};

#endif // __PARAMS__DmaDevice__
