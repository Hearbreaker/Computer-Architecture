// Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/StateMachine.py:1028
// L1Cache: MSI L1 Cache

#include <sys/types.h>
#include <unistd.h>

#include <cassert>

#include "base/misc.hh"
#include "debug/RubySlicc.hh"
#include "mem/protocol/L1Cache_Controller.hh"
#include "mem/protocol/L1Cache_Event.hh"
#include "mem/protocol/L1Cache_State.hh"
#include "mem/protocol/Types.hh"
#include "mem/ruby/common/Global.hh"
#include "mem/ruby/slicc_interface/RubySlicc_includes.hh"
#include "mem/ruby/system/System.hh"

using namespace std;

void
L1Cache_Controller::wakeup()
{
    int counter = 0;
    while (true) {
        // Some cases will put us into an infinite loop without this limit
        assert(counter <= m_transitions_per_cycle);
        if (counter == m_transitions_per_cycle) {
            // Count how often we are fully utilized
            g_system_ptr->getProfiler()->controllerBusy(m_machineID);

            // Wakeup in another cycle and try again
            g_eventQueue_ptr->scheduleEvent(this, 1);
            break;
        }
            // L1CacheInPort forwardRequestNetwork_in
            m_cur_in_port_rank = 0;
                        if ((((*m_L1Cache_forwardToCache_ptr)).isReady())) {
                            {
                                // Declare message
                                const RequestMsg* in_msg_ptr M5_VAR_USED;
                                in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_L1Cache_forwardToCache_ptr)).peek());
                                assert(in_msg_ptr != NULL); // Check the cast result
                                if ( (m_is_blocking == true) &&
                                     (m_block_map.count(in_msg_ptr->m_Address) == 1) ) {
                                     if (m_block_map[in_msg_ptr->m_Address] != &(*m_L1Cache_forwardToCache_ptr)) {
                                        (*m_L1Cache_forwardToCache_ptr).delayHead();
                                        continue;
                                     }
                                }
                                        
                            L1Cache_Entry* cache_entry
                             = (getCacheEntry(((*in_msg_ptr)).m_Address));
                            L1Cache_TBE* tbe
                             = (((*m_L1Cache_TBEs_ptr)).lookup(((*in_msg_ptr)).m_Address));
                                if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_GETM)) {
                                    DPRINTF(RubySlicc, "MSI-cache.sm:259: L1 - forwardRequestNetwork_in port: GETM request for address %s\n", ((*in_msg_ptr)).m_Address);
                                    {
                                        Address addr = ((*in_msg_ptr)).m_Address;

                                        TransitionResult result = doTransition(L1Cache_Event_Fwd_GetM, cache_entry, tbe, addr);

                                        if (result == TransitionResult_Valid) {
                                            counter++;
                                            continue; // Check the first port again
                                        }

                                        if (result == TransitionResult_ResourceStall) {
                                            g_eventQueue_ptr->scheduleEvent(this, 1);

                                            // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                        }
                                    }
                                    ;
                                } else {
                                        if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_GETS)) {
                                            DPRINTF(RubySlicc, "MSI-cache.sm:263: L1 - forwardRequestNetwork_in port: GETS request for address %s\n", ((*in_msg_ptr)).m_Address);
                                            {
                                                Address addr = ((*in_msg_ptr)).m_Address;

                                                TransitionResult result = doTransition(L1Cache_Event_Fwd_GetS, cache_entry, tbe, addr);

                                                if (result == TransitionResult_Valid) {
                                                    counter++;
                                                    continue; // Check the first port again
                                                }

                                                if (result == TransitionResult_ResourceStall) {
                                                    g_eventQueue_ptr->scheduleEvent(this, 1);

                                                    // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                }
                                            }
                                            ;
                                        } else {
                                                if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_INV)) {
                                                    DPRINTF(RubySlicc, "MSI-cache.sm:267: L1 - forwardRequestNetwork_in port: INV request for address %s\n", ((*in_msg_ptr)).m_Address);
                                                    {
                                                        Address addr = ((*in_msg_ptr)).m_Address;

                                                        TransitionResult result = doTransition(L1Cache_Event_Inv, cache_entry, tbe, addr);

                                                        if (result == TransitionResult_Valid) {
                                                            counter++;
                                                            continue; // Check the first port again
                                                        }

                                                        if (result == TransitionResult_ResourceStall) {
                                                            g_eventQueue_ptr->scheduleEvent(this, 1);

                                                            // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                        }
                                                    }
                                                    ;
                                                } else {
                                                        if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_WB_ACK)) {
                                                            DPRINTF(RubySlicc, "MSI-cache.sm:271: L1 - forwardRequestNetwork_in port: WB_ACK messsage for address %s\n", ((*in_msg_ptr)).m_Address);
                                                            {
                                                                Address addr = ((*in_msg_ptr)).m_Address;

                                                                TransitionResult result = doTransition(L1Cache_Event_WB_Ack, cache_entry, tbe, addr);

                                                                if (result == TransitionResult_Valid) {
                                                                    counter++;
                                                                    continue; // Check the first port again
                                                                }

                                                                if (result == TransitionResult_ResourceStall) {
                                                                    g_eventQueue_ptr->scheduleEvent(this, 1);

                                                                    // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                }
                                                            }
                                                            ;
                                                        } else {
                                                            DPRINTF(RubySlicc, "MSI-cache.sm:275: Error! L1 - Unexpected Forwarded Message => address: %s, Request Type: %s\n", ((*in_msg_ptr)).m_Address, ((*in_msg_ptr)).m_Type);
                                                            char c;
                                                            cerr << "Runtime Error at MSI-cache.sm:276, Ruby Time: "
                                                                 << g_eventQueue_ptr->getTime() << ": "
                                                                 << ("MSI_example L1 - Unexpected message in forwardToCache buffer")
                                                                 << ", PID: " << getpid() << endl
                                                                 << "press return to continue." << endl;
                                                            cin.get(c);
                                                            abort();
                                                            ;
                                                        }
                                                    }
                                                }
                                            }
                                            }
                                        }
            // L1CacheInPort responseNetwork_in
            m_cur_in_port_rank = 0;
                        if ((((*m_L1Cache_responseToCache_ptr)).isReady())) {
                            {
                                // Declare message
                                const ResponseMsg* in_msg_ptr M5_VAR_USED;
                                in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_L1Cache_responseToCache_ptr)).peek());
                                assert(in_msg_ptr != NULL); // Check the cast result
                                if ( (m_is_blocking == true) &&
                                     (m_block_map.count(in_msg_ptr->m_Address) == 1) ) {
                                     if (m_block_map[in_msg_ptr->m_Address] != &(*m_L1Cache_responseToCache_ptr)) {
                                        (*m_L1Cache_responseToCache_ptr).delayHead();
                                        continue;
                                     }
                                }
                                        
                            L1Cache_Entry* cache_entry
                             = (getCacheEntry(((*in_msg_ptr)).m_Address));
                            L1Cache_TBE* tbe
                             = (((*m_L1Cache_TBEs_ptr)).lookup(((*in_msg_ptr)).m_Address));
                                if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_DATA_FROM_DIR)) {
                                        if ((((*in_msg_ptr)).m_AckCount == (0))) {
                                            DPRINTF(RubySlicc, "MSI-cache.sm:294: L1 - responseNetwork_in port: DATA_FROM_DIR_NO_ACKS reply for address %s\n", ((*in_msg_ptr)).m_Address);
                                            {
                                                Address addr = ((*in_msg_ptr)).m_Address;

                                                TransitionResult result = doTransition(L1Cache_Event_Data_from_Dir_No_Acks, cache_entry, tbe, addr);

                                                if (result == TransitionResult_Valid) {
                                                    counter++;
                                                    continue; // Check the first port again
                                                }

                                                if (result == TransitionResult_ResourceStall) {
                                                    g_eventQueue_ptr->scheduleEvent(this, 1);

                                                    // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                }
                                            }
                                            ;
                                        } else {
                                                if ((((getPendingAcks(tbe)) - ((*in_msg_ptr)).m_AckCount) == (0))) {
                                                    DPRINTF(RubySlicc, "MSI-cache.sm:298: L1 - responseNetwork_in port: DATA_FROM_DIR_ACK_CNT reply for address %s - Data arrived after last Inv_Ack\n", ((*in_msg_ptr)).m_Address);
                                                    {
                                                        Address addr = ((*in_msg_ptr)).m_Address;

                                                        TransitionResult result = doTransition(L1Cache_Event_Data_from_Dir_Ack_Cnt_Last, cache_entry, tbe, addr);

                                                        if (result == TransitionResult_Valid) {
                                                            counter++;
                                                            continue; // Check the first port again
                                                        }

                                                        if (result == TransitionResult_ResourceStall) {
                                                            g_eventQueue_ptr->scheduleEvent(this, 1);

                                                            // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                        }
                                                    }
                                                    ;
                                                } else {
                                                    DPRINTF(RubySlicc, "MSI-cache.sm:301: L1 - responseNetwork_in port: DATA_FROM_DIR_ACK_CNT reply for address %s\n", ((*in_msg_ptr)).m_Address);
                                                    {
                                                        Address addr = ((*in_msg_ptr)).m_Address;

                                                        TransitionResult result = doTransition(L1Cache_Event_Data_from_Dir_Ack_Cnt, cache_entry, tbe, addr);

                                                        if (result == TransitionResult_Valid) {
                                                            counter++;
                                                            continue; // Check the first port again
                                                        }

                                                        if (result == TransitionResult_ResourceStall) {
                                                            g_eventQueue_ptr->scheduleEvent(this, 1);

                                                            // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                        }
                                                    }
                                                    ;
                                                }
                                            }
                                        } else {
                                                if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_DATA_FROM_OWNER)) {
                                                    DPRINTF(RubySlicc, "MSI-cache.sm:307: L1 - responseNetwork_in port: DATA_FROM_OWNER reply for address %s\n", ((*in_msg_ptr)).m_Address);
                                                    {
                                                        Address addr = ((*in_msg_ptr)).m_Address;

                                                        TransitionResult result = doTransition(L1Cache_Event_Data_from_Owner, cache_entry, tbe, addr);

                                                        if (result == TransitionResult_Valid) {
                                                            counter++;
                                                            continue; // Check the first port again
                                                        }

                                                        if (result == TransitionResult_ResourceStall) {
                                                            g_eventQueue_ptr->scheduleEvent(this, 1);

                                                            // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                        }
                                                    }
                                                    ;
                                                } else {
                                                        if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_ACK)) {
                                                                if ((((getPendingAcks(tbe)) - ((*in_msg_ptr)).m_AckCount) == (0))) {
                                                                    DPRINTF(RubySlicc, "MSI-cache.sm:312: L1 - responseNetwork_in port: INV_Ack_all for address %s\n", ((*in_msg_ptr)).m_Address);
                                                                    {
                                                                        Address addr = ((*in_msg_ptr)).m_Address;

                                                                        TransitionResult result = doTransition(L1Cache_Event_Inv_Ack_all, cache_entry, tbe, addr);

                                                                        if (result == TransitionResult_Valid) {
                                                                            counter++;
                                                                            continue; // Check the first port again
                                                                        }

                                                                        if (result == TransitionResult_ResourceStall) {
                                                                            g_eventQueue_ptr->scheduleEvent(this, 1);

                                                                            // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                        }
                                                                    }
                                                                    ;
                                                                } else {
                                                                    DPRINTF(RubySlicc, "MSI-cache.sm:315: L1 - responseNetwork_in port: INV_Ack for address %s\n", ((*in_msg_ptr)).m_Address);
                                                                    {
                                                                        Address addr = ((*in_msg_ptr)).m_Address;

                                                                        TransitionResult result = doTransition(L1Cache_Event_Inv_Ack, cache_entry, tbe, addr);

                                                                        if (result == TransitionResult_Valid) {
                                                                            counter++;
                                                                            continue; // Check the first port again
                                                                        }

                                                                        if (result == TransitionResult_ResourceStall) {
                                                                            g_eventQueue_ptr->scheduleEvent(this, 1);

                                                                            // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                                                        }
                                                                    }
                                                                    ;
                                                                }
                                                            } else {
                                                                DPRINTF(RubySlicc, "MSI-cache.sm:320: Error! L1 - Unexpected Coherence Response Message => address: %s, Request Type: %s\n", ((*in_msg_ptr)).m_Address, ((*in_msg_ptr)).m_Type);
                                                                char c;
                                                                cerr << "Runtime Error at MSI-cache.sm:321, Ruby Time: "
                                                                     << g_eventQueue_ptr->getTime() << ": "
                                                                     << ("MSI_example L1 - Unexpected message in reponseToCache buffer")
                                                                     << ", PID: " << getpid() << endl
                                                                     << "press return to continue." << endl;
                                                                cin.get(c);
                                                                abort();
                                                                ;
                                                            }
                                                        }
                                                    }
                                                    }
                                                }
            // L1CacheInPort mandatoryQueue_in
            m_cur_in_port_rank = 0;
                        if ((((*m_L1Cache_mandatoryQueue_ptr)).isReady())) {
                            {
                                // Declare message
                                const RubyRequest* in_msg_ptr M5_VAR_USED;
                                in_msg_ptr = dynamic_cast<const RubyRequest *>(((*m_L1Cache_mandatoryQueue_ptr)).peek());
                                assert(in_msg_ptr != NULL); // Check the cast result
                                if ( (m_is_blocking == true) &&
                                     (m_block_map.count(in_msg_ptr->m_LineAddress) == 1) ) {
                                     if (m_block_map[in_msg_ptr->m_LineAddress] != &(*m_L1Cache_mandatoryQueue_ptr)) {
                                        (*m_L1Cache_mandatoryQueue_ptr).delayHead();
                                        continue;
                                     }
                                }
                                        
                            L1Cache_Entry* cache_entry
                             = (getCacheEntry(((*in_msg_ptr)).m_LineAddress));
                                if (((cache_entry == NULL) && ((((*m_cacheMemory_ptr)).cacheAvail(((*in_msg_ptr)).m_LineAddress)) == (false)))) {
                                    DPRINTF(RubySlicc, "MSI-cache.sm:337: L1 - mandatoryQueue_in request for address %s - Need to replace entry\n", ((*in_msg_ptr)).m_LineAddress);
                                    {
                                        Address addr = (((*m_cacheMemory_ptr)).cacheProbe(((*in_msg_ptr)).m_LineAddress));

                                        TransitionResult result = doTransition(L1Cache_Event_Replacement, (getCacheEntry((((*m_cacheMemory_ptr)).cacheProbe(((*in_msg_ptr)).m_LineAddress)))), (((*m_L1Cache_TBEs_ptr)).lookup((((*m_cacheMemory_ptr)).cacheProbe(((*in_msg_ptr)).m_LineAddress)))), addr);

                                        if (result == TransitionResult_Valid) {
                                            counter++;
                                            continue; // Check the first port again
                                        }

                                        if (result == TransitionResult_ResourceStall) {
                                            g_eventQueue_ptr->scheduleEvent(this, 1);

                                            // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                        }
                                    }
                                    ;
                                } else {
                                    DPRINTF(RubySlicc, "MSI-cache.sm:344: L1 - mandatoryQueue_in request of type %s for address %s - No replacement necessary\n", ((*in_msg_ptr)).m_Type, ((*in_msg_ptr)).m_LineAddress);
                                    {
                                        Address addr = ((*in_msg_ptr)).m_LineAddress;

                                        TransitionResult result = doTransition((mandatory_request_type_to_event(((*in_msg_ptr)).m_Type)), cache_entry, (((*m_L1Cache_TBEs_ptr)).lookup(((*in_msg_ptr)).m_LineAddress)), addr);

                                        if (result == TransitionResult_Valid) {
                                            counter++;
                                            continue; // Check the first port again
                                        }

                                        if (result == TransitionResult_ResourceStall) {
                                            g_eventQueue_ptr->scheduleEvent(this, 1);

                                            // Cannot do anything with this transition, go check next doable transition (mostly likely of next port)
                                        }
                                    }
                                    ;
                                }
                                }
                            }
        break;  // If we got this far, we have nothing left todo
    }
    // g_eventQueue_ptr->scheduleEvent(this, 1);
}
