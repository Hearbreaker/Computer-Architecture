// Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/StateMachine.py:1088
// L1Cache: MSI L1 Cache

#include <cassert>

#include "base/misc.hh"
#include "base/trace.hh"
#include "debug/ProtocolTrace.hh"
#include "debug/RubyGenerated.hh"
#include "mem/protocol/L1Cache_Controller.hh"
#include "mem/protocol/L1Cache_Event.hh"
#include "mem/protocol/L1Cache_State.hh"
#include "mem/protocol/Types.hh"
#include "mem/ruby/common/Global.hh"
#include "mem/ruby/system/System.hh"

#define HASH_FUN(state, event)  ((int(state)*L1Cache_Event_NUM)+int(event))

#define GET_TRANSITION_COMMENT() (L1Cache_transitionComment.str())
#define CLEAR_TRANSITION_COMMENT() (L1Cache_transitionComment.str(""))

TransitionResult
L1Cache_Controller::doTransition(L1Cache_Event event,
                                  L1Cache_Entry* m_cache_entry_ptr,
                                  L1Cache_TBE* m_tbe_ptr,
                                  const Address &addr)
{
L1Cache_State state = getState(m_tbe_ptr, m_cache_entry_ptr, addr);
    L1Cache_State next_state = state;

    DPRINTF(RubyGenerated, "%s, Time: %lld, state: %s, event: %s, addr: %s\n",
            *this,
            g_eventQueue_ptr->getTime(),
            L1Cache_State_to_string(state),
            L1Cache_Event_to_string(event),
            addr);

    TransitionResult result =
doTransitionWorker(event, state, next_state, m_tbe_ptr, m_cache_entry_ptr, addr);
    if (result == TransitionResult_Valid) {
        DPRINTF(RubyGenerated, "next_state: %s\n",
                L1Cache_State_to_string(next_state));
        m_profiler.countTransition(state, event);
        DPRINTFR(ProtocolTrace, "%15d %3s %10s%20s %6s>%-6s %s %s\n",
                 curTick(), m_version, "L1Cache",
                 L1Cache_Event_to_string(event),
                 L1Cache_State_to_string(state),
                 L1Cache_State_to_string(next_state),
                 addr, GET_TRANSITION_COMMENT());

        CLEAR_TRANSITION_COMMENT();
setState(m_tbe_ptr, m_cache_entry_ptr, addr, next_state);
setAccessPermission(m_cache_entry_ptr, addr, next_state);
    } else if (result == TransitionResult_ResourceStall) {
        DPRINTFR(ProtocolTrace, "%15s %3s %10s%20s %6s>%-6s %s %s\n",
                 curTick(), m_version, "L1Cache",
                 L1Cache_Event_to_string(event),
                 L1Cache_State_to_string(state),
                 L1Cache_State_to_string(next_state),
                 addr, "Resource Stall");
    } else if (result == TransitionResult_ProtocolStall) {
        DPRINTF(RubyGenerated, "stalling\n");
        DPRINTFR(ProtocolTrace, "%15s %3s %10s%20s %6s>%-6s %s %s\n",
                 curTick(), m_version, "L1Cache",
                 L1Cache_Event_to_string(event),
                 L1Cache_State_to_string(state),
                 L1Cache_State_to_string(next_state),
                 addr, "Protocol Stall");
    }

    return result;
}

TransitionResult
L1Cache_Controller::doTransitionWorker(L1Cache_Event event,
                                        L1Cache_State state,
                                        L1Cache_State& next_state,
                                        L1Cache_TBE*& m_tbe_ptr,
                                        L1Cache_Entry*& m_cache_entry_ptr,
                                        const Address& addr)
{
    switch(HASH_FUN(state, event)) {
  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Load):
    next_state = L1Cache_State_IS_D;
    if (!(*m_L1Cache_requestFromCache_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    p_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    i_allocateL1CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    as_issueGetS(m_tbe_ptr, m_cache_entry_ptr, addr);
    v_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(L1Cache_State_IS_D, L1Cache_Event_Data_from_Dir_No_Acks):
  case HASH_FUN(L1Cache_State_IS_D, L1Cache_Event_Data_from_Owner):
    next_state = L1Cache_State_S;
    u_writeDataToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    rx_load_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    w_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(L1Cache_State_IS_D, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_IS_D, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_IS_D, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_IS_D, L1Cache_Event_Replacement):
  case HASH_FUN(L1Cache_State_IS_D, L1Cache_Event_Inv):
  case HASH_FUN(L1Cache_State_IM_A, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_IM_A, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_IM_A, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_IM_A, L1Cache_Event_Replacement):
  case HASH_FUN(L1Cache_State_IM_A, L1Cache_Event_Fwd_GetS):
  case HASH_FUN(L1Cache_State_IM_A, L1Cache_Event_Fwd_GetM):
  case HASH_FUN(L1Cache_State_IM_AD, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_IM_AD, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_IM_AD, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_IM_AD, L1Cache_Event_Replacement):
  case HASH_FUN(L1Cache_State_IM_AD, L1Cache_Event_Fwd_GetS):
  case HASH_FUN(L1Cache_State_IM_AD, L1Cache_Event_Fwd_GetM):
  case HASH_FUN(L1Cache_State_SI_A, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_SI_A, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_SI_A, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_SI_A, L1Cache_Event_Replacement):
  case HASH_FUN(L1Cache_State_SM_AD, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_SM_AD, L1Cache_Event_Replacement):
  case HASH_FUN(L1Cache_State_SM_AD, L1Cache_Event_Fwd_GetS):
  case HASH_FUN(L1Cache_State_SM_AD, L1Cache_Event_Fwd_GetM):
  case HASH_FUN(L1Cache_State_SM_A, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_SM_A, L1Cache_Event_Replacement):
  case HASH_FUN(L1Cache_State_SM_A, L1Cache_Event_Fwd_GetS):
  case HASH_FUN(L1Cache_State_SM_A, L1Cache_Event_Fwd_GetM):
  case HASH_FUN(L1Cache_State_MI_A, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_MI_A, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_MI_A, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_MI_A, L1Cache_Event_Replacement):
  case HASH_FUN(L1Cache_State_II_A, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_II_A, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_II_A, L1Cache_Event_Store):
  case HASH_FUN(L1Cache_State_II_A, L1Cache_Event_Replacement):
    return TransitionResult_ProtocolStall;
  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Store):
    next_state = L1Cache_State_IM_AD;
    if (!(*m_L1Cache_requestFromCache_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    p_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    i_allocateL1CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    am_issueGetM(m_tbe_ptr, m_cache_entry_ptr, addr);
    v_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(L1Cache_State_IM_AD, L1Cache_Event_Data_from_Dir_Ack_Cnt_Last):
  case HASH_FUN(L1Cache_State_SM_AD, L1Cache_Event_Data_from_Dir_Ack_Cnt_Last):
    next_state = L1Cache_State_M;
    u_writeDataToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    q_updateAckCount(m_tbe_ptr, m_cache_entry_ptr, addr);
    sx_store_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    w_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(L1Cache_State_IM_AD, L1Cache_Event_Data_from_Dir_No_Acks):
  case HASH_FUN(L1Cache_State_IM_AD, L1Cache_Event_Data_from_Owner):
    next_state = L1Cache_State_M;
    u_writeDataToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    sx_store_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    w_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(L1Cache_State_IM_AD, L1Cache_Event_Data_from_Dir_Ack_Cnt):
    next_state = L1Cache_State_IM_A;
    u_writeDataToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    q_updateAckCount(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(L1Cache_State_IM_A, L1Cache_Event_Inv_Ack_all):
    next_state = L1Cache_State_M;
    q_updateAckCount(m_tbe_ptr, m_cache_entry_ptr, addr);
    sx_store_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    w_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(L1Cache_State_I, L1Cache_Event_Inv):
    if (!(*m_L1Cache_responseFromCache_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    fi_sendInvAck(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popForwardedRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(L1Cache_State_I, L1Cache_Event_WB_Ack):
    o_popForwardedRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(L1Cache_State_IM_A, L1Cache_Event_Inv_Ack):
  case HASH_FUN(L1Cache_State_IM_AD, L1Cache_Event_Inv_Ack):
  case HASH_FUN(L1Cache_State_SM_A, L1Cache_Event_Inv_Ack):
  case HASH_FUN(L1Cache_State_SM_AD, L1Cache_Event_Inv_Ack):
    q_updateAckCount(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(L1Cache_State_S, L1Cache_Event_Inv):
    next_state = L1Cache_State_I;
    if (!(*m_L1Cache_responseFromCache_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    fi_sendInvAck(m_tbe_ptr, m_cache_entry_ptr, addr);
    h_deallocateL1CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    forward_eviction_to_cpu(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popForwardedRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(L1Cache_State_S, L1Cache_Event_Replacement):
    next_state = L1Cache_State_SI_A;
    if (!(*m_L1Cache_requestFromCache_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    bs_issuePUTS(m_tbe_ptr, m_cache_entry_ptr, addr);
    v_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    x_copyDataFromCacheToTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(L1Cache_State_SI_A, L1Cache_Event_WB_Ack):
  case HASH_FUN(L1Cache_State_MI_A, L1Cache_Event_WB_Ack):
  case HASH_FUN(L1Cache_State_II_A, L1Cache_Event_WB_Ack):
    next_state = L1Cache_State_I;
    forward_eviction_to_cpu(m_tbe_ptr, m_cache_entry_ptr, addr);
    w_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    h_deallocateL1CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popForwardedRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(L1Cache_State_S, L1Cache_Event_Store):
    next_state = L1Cache_State_SM_AD;
    if (!(*m_L1Cache_requestFromCache_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    p_profileMiss(m_tbe_ptr, m_cache_entry_ptr, addr);
    am_issueGetM(m_tbe_ptr, m_cache_entry_ptr, addr);
    v_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    x_copyDataFromCacheToTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(L1Cache_State_SM_AD, L1Cache_Event_Data_from_Dir_No_Acks):
  case HASH_FUN(L1Cache_State_SM_AD, L1Cache_Event_Data_from_Owner):
    next_state = L1Cache_State_M;
    u_writeDataToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    w_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    sx_store_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(L1Cache_State_SM_AD, L1Cache_Event_Data_from_Dir_Ack_Cnt):
    next_state = L1Cache_State_SM_A;
    q_updateAckCount(m_tbe_ptr, m_cache_entry_ptr, addr);
    u_writeDataToCache(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(L1Cache_State_SM_A, L1Cache_Event_Inv_Ack_all):
    next_state = L1Cache_State_M;
    q_updateAckCount(m_tbe_ptr, m_cache_entry_ptr, addr);
    w_deallocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    sx_store_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    n_popResponseQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(L1Cache_State_SM_AD, L1Cache_Event_Inv):
    next_state = L1Cache_State_IM_AD;
    if (!(*m_L1Cache_responseFromCache_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    fi_sendInvAck(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popForwardedRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Fwd_GetM):
    next_state = L1Cache_State_I;
    if (!(*m_L1Cache_responseFromCache_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    e_sendDataFromCacheToRequestor(m_tbe_ptr, m_cache_entry_ptr, addr);
    forward_eviction_to_cpu(m_tbe_ptr, m_cache_entry_ptr, addr);
    h_deallocateL1CacheBlock(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popForwardedRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Replacement):
    next_state = L1Cache_State_MI_A;
    if (!(*m_L1Cache_requestFromCache_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    bm_issuePUTM(m_tbe_ptr, m_cache_entry_ptr, addr);
    v_allocateTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    x_copyDataFromCacheToTBE(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(L1Cache_State_MI_A, L1Cache_Event_Fwd_GetM):
    next_state = L1Cache_State_II_A;
    if (!(*m_L1Cache_responseFromCache_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    ee_sendDataFromTBEToRequestor(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popForwardedRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(L1Cache_State_MI_A, L1Cache_Event_Fwd_GetS):
    next_state = L1Cache_State_SI_A;
    if (!(*m_L1Cache_responseFromCache_ptr).areNSlotsAvailable(2))
        return TransitionResult_ResourceStall;
    ee_sendDataFromTBEToRequestor(m_tbe_ptr, m_cache_entry_ptr, addr);
    dee_sendDataFromTBEToDir(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popForwardedRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(L1Cache_State_SI_A, L1Cache_Event_Inv):
    next_state = L1Cache_State_II_A;
    if (!(*m_L1Cache_responseFromCache_ptr).areNSlotsAvailable(1))
        return TransitionResult_ResourceStall;
    fi_sendInvAck(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popForwardedRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Fwd_GetS):
    next_state = L1Cache_State_S;
    if (!(*m_L1Cache_responseFromCache_ptr).areNSlotsAvailable(2))
        return TransitionResult_ResourceStall;
    e_sendDataFromCacheToRequestor(m_tbe_ptr, m_cache_entry_ptr, addr);
    de_sendDataFromCacheToDir(m_tbe_ptr, m_cache_entry_ptr, addr);
    o_popForwardedRequestQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(L1Cache_State_S, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_S, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_SM_AD, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_SM_AD, L1Cache_Event_Ifetch):
  case HASH_FUN(L1Cache_State_SM_A, L1Cache_Event_Load):
  case HASH_FUN(L1Cache_State_SM_A, L1Cache_Event_Ifetch):
    r_load_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;
  case HASH_FUN(L1Cache_State_M, L1Cache_Event_Store):
    s_store_hit(m_tbe_ptr, m_cache_entry_ptr, addr);
    m_popMandatoryQueue(m_tbe_ptr, m_cache_entry_ptr, addr);
    return TransitionResult_Valid;
      default:
        fatal("Invalid transition\n"
              "%s time: %d addr: %s event: %s state: %s\n",
              name(), g_eventQueue_ptr->getTime(), addr, event, state);
    }
    return TransitionResult_Valid;
}
