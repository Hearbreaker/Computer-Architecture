// Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/StateMachine.py:1088
// Directory: Directory protocol

#include <cassert>

#include "base/misc.hh"
#include "base/trace.hh"
#include "debug/ProtocolTrace.hh"
#include "debug/RubyGenerated.hh"
#include "mem/protocol/Directory_Controller.hh"
#include "mem/protocol/Directory_Event.hh"
#include "mem/protocol/Directory_State.hh"
#include "mem/protocol/Types.hh"
#include "mem/ruby/common/Global.hh"
#include "mem/ruby/system/System.hh"

#define HASH_FUN(state, event)  ((int(state)*Directory_Event_NUM)+int(event))

#define GET_TRANSITION_COMMENT() (Directory_transitionComment.str())
#define CLEAR_TRANSITION_COMMENT() (Directory_transitionComment.str(""))

TransitionResult
Directory_Controller::doTransition(Directory_Event event,
                                  Directory_TBE* m_tbe_ptr,
                                  const Address &addr)
{
Directory_State state = getState(m_tbe_ptr, addr);
    Directory_State next_state = state;

    DPRINTF(RubyGenerated, "%s, Time: %lld, state: %s, event: %s, addr: %s\n",
            *this,
            g_eventQueue_ptr->getTime(),
            Directory_State_to_string(state),
            Directory_Event_to_string(event),
            addr);

    TransitionResult result =
doTransitionWorker(event, state, next_state, m_tbe_ptr, addr);
    if (result == TransitionResult_Valid) {
        DPRINTF(RubyGenerated, "next_state: %s\n",
                Directory_State_to_string(next_state));
        m_profiler.countTransition(state, event);
        DPRINTFR(ProtocolTrace, "%15d %3s %10s%20s %6s>%-6s %s %s\n",
                 curTick(), m_version, "Directory",
                 Directory_Event_to_string(event),
                 Directory_State_to_string(state),
                 Directory_State_to_string(next_state),
                 addr, GET_TRANSITION_COMMENT());

        CLEAR_TRANSITION_COMMENT();
setState(m_tbe_ptr, addr, next_state);
setAccessPermission(addr, next_state);
    } else if (result == TransitionResult_ResourceStall) {
        DPRINTFR(ProtocolTrace, "%15s %3s %10s%20s %6s>%-6s %s %s\n",
                 curTick(), m_version, "Directory",
                 Directory_Event_to_string(event),
                 Directory_State_to_string(state),
                 Directory_State_to_string(next_state),
                 addr, "Resource Stall");
    } else if (result == TransitionResult_ProtocolStall) {
        DPRINTF(RubyGenerated, "stalling\n");
        DPRINTFR(ProtocolTrace, "%15s %3s %10s%20s %6s>%-6s %s %s\n",
                 curTick(), m_version, "Directory",
                 Directory_Event_to_string(event),
                 Directory_State_to_string(state),
                 Directory_State_to_string(next_state),
                 addr, "Protocol Stall");
    }

    return result;
}

TransitionResult
Directory_Controller::doTransitionWorker(Directory_Event event,
                                        Directory_State state,
                                        Directory_State& next_state,
                                        Directory_TBE*& m_tbe_ptr,
                                        const Address& addr)
{
    switch(HASH_FUN(state, event)) {
  case HASH_FUN(Directory_State_I, Directory_Event_GETS):
    next_state = Directory_State_IS_D;
    if (!(*m_memBuffer_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    vv_allocateTBEFromRequestNet(m_tbe_ptr, addr);
    ars2_addRequestorToSharers(m_tbe_ptr, addr);
    qf_queueMemoryFetchRequest(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(Directory_State_I, Directory_Event_GETM):
    next_state = Directory_State_IM_D;
    if (!(*m_memBuffer_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    vv_allocateTBEFromRequestNet(m_tbe_ptr, addr);
    e_ownerIsRequestor(m_tbe_ptr, addr);
    qf_queueMemoryFetchRequest(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(Directory_State_I, Directory_Event_PUTS_Last):
  case HASH_FUN(Directory_State_I, Directory_Event_PUTS_NotLast):
  case HASH_FUN(Directory_State_I, Directory_Event_PUTM_NotOwner):
  case HASH_FUN(Directory_State_M, Directory_Event_PUTS_Last):
  case HASH_FUN(Directory_State_M, Directory_Event_PUTS_NotLast):
  case HASH_FUN(Directory_State_M, Directory_Event_PUTM_NotOwner):
    if (!(*m_Directory_forwardFromDir_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    a_sendWriteBackAck(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(Directory_State_S, Directory_Event_GETS):
    if (!(*m_Directory_responseFromDir_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    ars2_addRequestorToSharers(m_tbe_ptr, addr);
    ds_sendSharedData(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(Directory_State_S, Directory_Event_GETM):
    next_state = Directory_State_M;
    if (!(*m_Directory_forwardFromDir_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    if (!(*m_Directory_responseFromDir_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    ds2_sendSharedData(m_tbe_ptr, addr);
    fwm_sendFwdInvToSharersMinusRequestor(m_tbe_ptr, addr);
    cs_clearSharers(m_tbe_ptr, addr);
    e_ownerIsRequestor(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(Directory_State_S, Directory_Event_PUTS_Last):
    next_state = Directory_State_I;
    if (!(*m_Directory_forwardFromDir_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    kk_removeRequestSharer(m_tbe_ptr, addr);
    a_sendWriteBackAck(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(Directory_State_S, Directory_Event_PUTS_NotLast):
  case HASH_FUN(Directory_State_S, Directory_Event_PUTM_NotOwner):
  case HASH_FUN(Directory_State_MI_A, Directory_Event_PUTS_NotLast):
  case HASH_FUN(Directory_State_MI_A, Directory_Event_PUTM_NotOwner):
  case HASH_FUN(Directory_State_MS_A, Directory_Event_PUTS_NotLast):
  case HASH_FUN(Directory_State_MS_A, Directory_Event_PUTM_NotOwner):
  case HASH_FUN(Directory_State_MS_A, Directory_Event_PUTM_Owner):
  case HASH_FUN(Directory_State_MS_D, Directory_Event_PUTS_NotLast):
  case HASH_FUN(Directory_State_MS_D, Directory_Event_PUTM_NotOwner):
  case HASH_FUN(Directory_State_MS_D, Directory_Event_PUTM_Owner):
    if (!(*m_Directory_forwardFromDir_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    kk_removeRequestSharer(m_tbe_ptr, addr);
    a_sendWriteBackAck(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(Directory_State_M, Directory_Event_PUTM_Owner):
    next_state = Directory_State_MI_A;
    if (!(*m_memBuffer_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    lq_queueMemoryWBRequest(m_tbe_ptr, addr);
    pl_writeDataToDirectory(m_tbe_ptr, addr);
    vv_allocateTBEFromRequestNet(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(Directory_State_M, Directory_Event_GETM):
    if (!(*m_Directory_forwardFromDir_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    f_forwardRequest(m_tbe_ptr, addr);
    e_ownerIsRequestor(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(Directory_State_M, Directory_Event_GETS):
    next_state = Directory_State_MS_D;
    if (!(*m_Directory_forwardFromDir_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    f_forwardRequest(m_tbe_ptr, addr);
    ars2_addRequestorToSharers(m_tbe_ptr, addr);
    aos_addOwnertoSharers(m_tbe_ptr, addr);
    vv_allocateTBEFromRequestNet(m_tbe_ptr, addr);
    i_popIncomingRequestQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(Directory_State_MI_A, Directory_Event_Memory_Ack):
    next_state = Directory_State_I;
    if (!(*m_Directory_forwardFromDir_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    la_sendWriteBackAck(m_tbe_ptr, addr);
    w_deallocateTBE(m_tbe_ptr, addr);
    c_clearOwner(m_tbe_ptr, addr);
    qm_popMemQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(Directory_State_MS_A, Directory_Event_Memory_Ack):
    next_state = Directory_State_S;
    w_deallocateTBE(m_tbe_ptr, addr);
    c_clearOwner(m_tbe_ptr, addr);
    qm_popMemQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(Directory_State_IS_D, Directory_Event_Memory_Data):
    next_state = Directory_State_S;
    if (!(*m_Directory_responseFromDir_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    w_deallocateTBE(m_tbe_ptr, addr);
    d_sendData(m_tbe_ptr, addr);
    qm_popMemQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(Directory_State_IM_D, Directory_Event_Memory_Data):
    next_state = Directory_State_M;
    if (!(*m_Directory_responseFromDir_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    w_deallocateTBE(m_tbe_ptr, addr);
    d_sendData(m_tbe_ptr, addr);
    qm_popMemQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(Directory_State_MS_D, Directory_Event_Data):
    next_state = Directory_State_MS_A;
    if (!(*m_memBuffer_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    lq2_queueMemoryWBRequest(m_tbe_ptr, addr);
    pl2_writeDataToDirectory(m_tbe_ptr, addr);
    pr_popIncomingResponseQueue(m_tbe_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(Directory_State_MI_A, Directory_Event_GETS):
  case HASH_FUN(Directory_State_MI_A, Directory_Event_GETM):
  case HASH_FUN(Directory_State_IM_D, Directory_Event_GETS):
  case HASH_FUN(Directory_State_IM_D, Directory_Event_GETM):
  case HASH_FUN(Directory_State_IS_D, Directory_Event_GETS):
  case HASH_FUN(Directory_State_IS_D, Directory_Event_GETM):
  case HASH_FUN(Directory_State_MS_D, Directory_Event_GETS):
  case HASH_FUN(Directory_State_MS_D, Directory_Event_GETM):
  case HASH_FUN(Directory_State_MS_A, Directory_Event_GETS):
  case HASH_FUN(Directory_State_MS_A, Directory_Event_GETM):
  case HASH_FUN(Directory_State_MS_A, Directory_Event_PUTS_Last):
  case HASH_FUN(Directory_State_MS_D, Directory_Event_PUTS_Last):
    return TransitionResult_ProtocolStall;
      default:
        fatal("Invalid transition\n"
              "%s time: %d addr: %s event: %s state: %s\n",
              name(), g_eventQueue_ptr->getTime(), addr, event, state);
    }
    return TransitionResult_Valid;
}
