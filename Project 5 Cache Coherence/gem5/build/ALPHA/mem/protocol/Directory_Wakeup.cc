// Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/StateMachine.py:1028
// Directory: Directory protocol

#include <sys/types.h>
#include <unistd.h>

#include <cassert>

#include "base/misc.hh"
#include "debug/RubySlicc.hh"
#include "mem/protocol/Directory_Controller.hh"
#include "mem/protocol/Directory_Event.hh"
#include "mem/protocol/Directory_State.hh"
#include "mem/protocol/Types.hh"
#include "mem/ruby/common/Global.hh"
#include "mem/ruby/slicc_interface/RubySlicc_includes.hh"
#include "mem/ruby/system/System.hh"

using namespace std;

void
Directory_Controller::wakeup()
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
            // DirectoryInPort responseQueue_in
            m_cur_in_port_rank = 0;
                        if ((((*m_Directory_responseToDir_ptr)).isReady())) {
                            {
                                // Declare message
                                const ResponseMsg* in_msg_ptr M5_VAR_USED;
                                in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_Directory_responseToDir_ptr)).peek());
                                assert(in_msg_ptr != NULL); // Check the cast result
                            Directory_TBE* tbe
                             = (((*m_Directory_TBEs_ptr)).lookup(((*in_msg_ptr)).m_Address));
                                if ((((*in_msg_ptr)).m_Type == CoherenceResponseType_DATA)) {
                                    DPRINTF(RubySlicc, "MSI-dir.sm:207: Directory - responseQueue_in port: DATA sent for address %s from machine %s\n", ((*in_msg_ptr)).m_Address, ((*in_msg_ptr)).m_Sender);
                                    {
                                        Address addr = ((*in_msg_ptr)).m_Address;

                                        TransitionResult result = doTransition(Directory_Event_Data, tbe, addr);

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
                                    char c;
                                    cerr << "Runtime Error at MSI-dir.sm:210, Ruby Time: "
                                         << g_eventQueue_ptr->getTime() << ": "
                                         << ("Directory: Invalid response message")
                                         << ", PID: " << getpid() << endl
                                         << "press return to continue." << endl;
                                    cin.get(c);
                                    abort();
                                    ;
                                }
                                }
                            }
            // DirectoryInPort requestQueue_in
            m_cur_in_port_rank = 0;
                        if ((((*m_Directory_requestToDir_ptr)).isReady())) {
                            {
                                // Declare message
                                const RequestMsg* in_msg_ptr M5_VAR_USED;
                                in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_Directory_requestToDir_ptr)).peek());
                                assert(in_msg_ptr != NULL); // Check the cast result
                            Directory_TBE* tbe
                             = (((*m_Directory_TBEs_ptr)).lookup(((*in_msg_ptr)).m_Address));
                                if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_GETS)) {
                                    DPRINTF(RubySlicc, "MSI-dir.sm:221: Directory - requestQueue_in port: GETS request for address %s from machine %s\n", ((*in_msg_ptr)).m_Address, ((*in_msg_ptr)).m_Requestor);
                                    {
                                        Address addr = ((*in_msg_ptr)).m_Address;

                                        TransitionResult result = doTransition(Directory_Event_GETS, tbe, addr);

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
                                        if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_GETM)) {
                                            DPRINTF(RubySlicc, "MSI-dir.sm:224: Directory - requestQueue_in port: GETM request for address %s from machine %s\n", ((*in_msg_ptr)).m_Address, ((*in_msg_ptr)).m_Requestor);
                                            {
                                                Address addr = ((*in_msg_ptr)).m_Address;

                                                TransitionResult result = doTransition(Directory_Event_GETM, tbe, addr);

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
                                                if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_PUTM)) {
                                                        if ((((*(getDirectoryEntry(((*in_msg_ptr)).m_Address))).m_Owner).isElement(((*in_msg_ptr)).m_Requestor))) {
                                                            DPRINTF(RubySlicc, "MSI-dir.sm:228: Directory - requestQueue_in port: PUTM for address %s from its owner machine %s\n", ((*in_msg_ptr)).m_Address, ((*in_msg_ptr)).m_Requestor);
                                                            {
                                                                Address addr = ((*in_msg_ptr)).m_Address;

                                                                TransitionResult result = doTransition(Directory_Event_PUTM_Owner, tbe, addr);

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
                                                            DPRINTF(RubySlicc, "MSI-dir.sm:231: Directory - requestQueue_in port: PUTM for address %s from  machine %s (not the owner)\n", ((*in_msg_ptr)).m_Address, ((*in_msg_ptr)).m_Requestor);
                                                            {
                                                                Address addr = ((*in_msg_ptr)).m_Address;

                                                                TransitionResult result = doTransition(Directory_Event_PUTM_NotOwner, tbe, addr);

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
                                                            if ((((*in_msg_ptr)).m_Type == CoherenceRequestType_PUTS)) {
                                                                    if ((((((*(getDirectoryEntry(((*in_msg_ptr)).m_Address))).m_Sharers).count()) < (2)) && (((*(getDirectoryEntry(((*in_msg_ptr)).m_Address))).m_Sharers).isElement(((*in_msg_ptr)).m_Requestor)))) {
                                                                        DPRINTF(RubySlicc, "MSI-dir.sm:236: Directory - requestQueue_in port: PUTS_LAST for address %s from machine %s\n", ((*in_msg_ptr)).m_Address, ((*in_msg_ptr)).m_Requestor);
                                                                        {
                                                                            Address addr = ((*in_msg_ptr)).m_Address;

                                                                            TransitionResult result = doTransition(Directory_Event_PUTS_Last, tbe, addr);

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
                                                                        DPRINTF(RubySlicc, "MSI-dir.sm:239: Directory - requestQueue_in port: PUTS for address %s from machine %s\n", ((*in_msg_ptr)).m_Address, ((*in_msg_ptr)).m_Requestor);
                                                                        {
                                                                            Address addr = ((*in_msg_ptr)).m_Address;

                                                                            TransitionResult result = doTransition(Directory_Event_PUTS_NotLast, tbe, addr);

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
                                                                    char c;
                                                                    cerr << "Runtime Error at MSI-dir.sm:250, Ruby Time: "
                                                                         << g_eventQueue_ptr->getTime() << ": "
                                                                         << ("Invalid message")
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
            // DirectoryInPort memQueue_in
            m_cur_in_port_rank = 0;
                        if ((((*m_memBuffer_ptr)).isReady())) {
                            {
                                // Declare message
                                const MemoryMsg* in_msg_ptr M5_VAR_USED;
                                in_msg_ptr = dynamic_cast<const MemoryMsg *>(((*m_memBuffer_ptr)).peek());
                                assert(in_msg_ptr != NULL); // Check the cast result
                            Directory_TBE* tbe
                             = (((*m_Directory_TBEs_ptr)).lookup(((*in_msg_ptr)).m_Address));
                                if ((((*in_msg_ptr)).m_Type == MemoryRequestType_MEMORY_READ)) {
                                    DPRINTF(RubySlicc, "MSI-dir.sm:263: Directory - memQueue_in port: MEMORY_READ for address %s from  machine %s\n", ((*in_msg_ptr)).m_Address, ((*in_msg_ptr)).m_OriginalRequestorMachId);
                                    {
                                        Address addr = ((*in_msg_ptr)).m_Address;

                                        TransitionResult result = doTransition(Directory_Event_Memory_Data, tbe, addr);

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
                                        if ((((*in_msg_ptr)).m_Type == MemoryRequestType_MEMORY_WB)) {
                                            DPRINTF(RubySlicc, "MSI-dir.sm:266: Directory - memQueue_in port: MEMORY_WB for address %s from  machine %s\n", ((*in_msg_ptr)).m_Address, ((*in_msg_ptr)).m_OriginalRequestorMachId);
                                            {
                                                Address addr = ((*in_msg_ptr)).m_Address;

                                                TransitionResult result = doTransition(Directory_Event_Memory_Ack, tbe, addr);

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
                                            DPRINTF(RubySlicc, "MSI-dir.sm:269: %s\n", ((*in_msg_ptr)).m_Type);
                                            char c;
                                            cerr << "Runtime Error at MSI-dir.sm:270, Ruby Time: "
                                                 << g_eventQueue_ptr->getTime() << ": "
                                                 << ("Invalid message")
                                                 << ", PID: " << getpid() << endl
                                                 << "press return to continue." << endl;
                                            cin.get(c);
                                            abort();
                                            ;
                                        }
                                    }
                                    }
                                }
        break;  // If we got this far, we have nothing left todo
    }
    // g_eventQueue_ptr->scheduleEvent(this, 1);
}
