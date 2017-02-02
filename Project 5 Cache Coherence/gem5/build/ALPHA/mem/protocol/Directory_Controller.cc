/** \file Directory_Controller.cc
 *
 * Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/StateMachine.py:431
 * Created by slicc definition of Module "Directory protocol"
 */

#include <sys/types.h>
#include <unistd.h>

#include <cassert>
#include <sstream>
#include <string>

#include "base/compiler.hh"
#include "base/cprintf.hh"
#include "debug/RubyGenerated.hh"
#include "debug/RubySlicc.hh"
#include "mem/protocol/Directory_Controller.hh"
#include "mem/protocol/Directory_Event.hh"
#include "mem/protocol/Directory_State.hh"
#include "mem/protocol/Types.hh"
#include "mem/ruby/common/Global.hh"
#include "mem/ruby/slicc_interface/RubySlicc_includes.hh"
#include "mem/ruby/system/System.hh"

using namespace std;
#include "mem/protocol/MessageBuffer.hh"
#include "mem/protocol/TBETable.hh"
Directory_Controller *
Directory_ControllerParams::create()
{
    return new Directory_Controller(this);
}

int Directory_Controller::m_num_controllers = 0;
Directory_ProfileDumper Directory_Controller::s_profileDumper;

// for adding information to the protocol debug trace
stringstream Directory_transitionComment;
#define APPEND_TRANSITION_COMMENT(str) (Directory_transitionComment << str)

/** \brief constructor */
Directory_Controller::Directory_Controller(const Params *p)
    : AbstractController(p)
{
    m_version = p->version;
    m_transitions_per_cycle = p->transitions_per_cycle;
    m_buffer_size = p->buffer_size;
    m_recycle_latency = p->recycle_latency;
    m_number_of_TBEs = p->number_of_TBEs;
    m_is_blocking = false;
    m_name = "Directory";
    m_max_in_port_rank = 1;
    m_directory_ptr = p->directory;
    m_memBuffer_ptr = p->memBuffer;
    m_directory_latency = p->directory_latency;
    m_send_evictions = p->send_evictions;
    m_num_controllers++;
}

void
Directory_Controller::init()
{
    MachineType machine_type;
    int base;

    m_machineID.type = MachineType_Directory;
    m_machineID.num = m_version;

    // initialize objects
    m_profiler.setVersion(m_version);
    s_profileDumper.registerProfiler(&m_profiler);

    machine_type = string_to_MachineType("Directory");
    base = MachineType_base_number(machine_type);
    m_Directory_requestToDir_ptr = m_net_ptr->getFromNetQueue(m_version + base, true, 2, "request");
    assert(m_Directory_requestToDir_ptr != NULL);
    m_Directory_requestToDir_ptr->setOrdering(true);
    if (m_buffer_size > 0) {
        m_Directory_requestToDir_ptr->resize(m_buffer_size);
    }
    m_Directory_requestToDir_ptr->setDescription("[Version " + to_string(m_version) + ", Directory, name=Directory_requestToDir]");

    m_Directory_requestToDir_ptr->setRecycleLatency(m_recycle_latency);
    machine_type = string_to_MachineType("Directory");
    base = MachineType_base_number(machine_type);
    m_Directory_responseToDir_ptr = m_net_ptr->getFromNetQueue(m_version + base, true, 4, "response");
    assert(m_Directory_responseToDir_ptr != NULL);
    m_Directory_responseToDir_ptr->setOrdering(true);
    if (m_buffer_size > 0) {
        m_Directory_responseToDir_ptr->resize(m_buffer_size);
    }
    m_Directory_responseToDir_ptr->setDescription("[Version " + to_string(m_version) + ", Directory, name=Directory_responseToDir]");

    m_Directory_responseToDir_ptr->setRecycleLatency(m_recycle_latency);
    machine_type = string_to_MachineType("Directory");
    base = MachineType_base_number(machine_type);
    m_Directory_forwardFromDir_ptr = m_net_ptr->getToNetQueue(m_version + base, true, 3, "forward");
    assert(m_Directory_forwardFromDir_ptr != NULL);
    m_Directory_forwardFromDir_ptr->setOrdering(true);
    if (m_buffer_size > 0) {
        m_Directory_forwardFromDir_ptr->resize(m_buffer_size);
    }
    m_Directory_forwardFromDir_ptr->setDescription("[Version " + to_string(m_version) + ", Directory, name=Directory_forwardFromDir]");

    m_Directory_forwardFromDir_ptr->setRecycleLatency(m_recycle_latency);
    machine_type = string_to_MachineType("Directory");
    base = MachineType_base_number(machine_type);
    m_Directory_responseFromDir_ptr = m_net_ptr->getToNetQueue(m_version + base, true, 4, "response");
    assert(m_Directory_responseFromDir_ptr != NULL);
    m_Directory_responseFromDir_ptr->setOrdering(true);
    if (m_buffer_size > 0) {
        m_Directory_responseFromDir_ptr->resize(m_buffer_size);
    }
    m_Directory_responseFromDir_ptr->setDescription("[Version " + to_string(m_version) + ", Directory, name=Directory_responseFromDir]");

    m_Directory_responseFromDir_ptr->setRecycleLatency(m_recycle_latency);
    m_Directory_TBEs_ptr  = new TBETable<Directory_TBE>(m_number_of_TBEs);
    assert(m_Directory_TBEs_ptr != NULL);

    (*m_Directory_responseToDir_ptr).setConsumer(this);
    (*m_Directory_requestToDir_ptr).setConsumer(this);
    (*m_memBuffer_ptr).setConsumer(this);

    (*m_Directory_responseToDir_ptr).setDescription("[Version " + to_string(m_version) + ", Directory, responseQueue_in]");
    (*m_Directory_requestToDir_ptr).setDescription("[Version " + to_string(m_version) + ", Directory, requestQueue_in]");
    (*m_memBuffer_ptr).setDescription("[Version " + to_string(m_version) + ", Directory, memQueue_in]");

    m_profiler.possibleTransition(Directory_State_I, Directory_Event_GETS);
    m_profiler.possibleTransition(Directory_State_I, Directory_Event_GETM);
    m_profiler.possibleTransition(Directory_State_I, Directory_Event_PUTS_Last);
    m_profiler.possibleTransition(Directory_State_I, Directory_Event_PUTS_NotLast);
    m_profiler.possibleTransition(Directory_State_I, Directory_Event_PUTM_NotOwner);
    m_profiler.possibleTransition(Directory_State_S, Directory_Event_GETS);
    m_profiler.possibleTransition(Directory_State_S, Directory_Event_GETM);
    m_profiler.possibleTransition(Directory_State_S, Directory_Event_PUTS_Last);
    m_profiler.possibleTransition(Directory_State_S, Directory_Event_PUTS_NotLast);
    m_profiler.possibleTransition(Directory_State_S, Directory_Event_PUTM_NotOwner);
    m_profiler.possibleTransition(Directory_State_M, Directory_Event_PUTM_Owner);
    m_profiler.possibleTransition(Directory_State_M, Directory_Event_GETM);
    m_profiler.possibleTransition(Directory_State_M, Directory_Event_GETS);
    m_profiler.possibleTransition(Directory_State_M, Directory_Event_PUTS_Last);
    m_profiler.possibleTransition(Directory_State_M, Directory_Event_PUTS_NotLast);
    m_profiler.possibleTransition(Directory_State_M, Directory_Event_PUTM_NotOwner);
    m_profiler.possibleTransition(Directory_State_MI_A, Directory_Event_Memory_Ack);
    m_profiler.possibleTransition(Directory_State_MI_A, Directory_Event_PUTS_NotLast);
    m_profiler.possibleTransition(Directory_State_MI_A, Directory_Event_PUTM_NotOwner);
    m_profiler.possibleTransition(Directory_State_MS_A, Directory_Event_Memory_Ack);
    m_profiler.possibleTransition(Directory_State_MS_A, Directory_Event_PUTS_NotLast);
    m_profiler.possibleTransition(Directory_State_MS_A, Directory_Event_PUTM_NotOwner);
    m_profiler.possibleTransition(Directory_State_MS_A, Directory_Event_PUTM_Owner);
    m_profiler.possibleTransition(Directory_State_IS_D, Directory_Event_Memory_Data);
    m_profiler.possibleTransition(Directory_State_IM_D, Directory_Event_Memory_Data);
    m_profiler.possibleTransition(Directory_State_MS_D, Directory_Event_Data);
    m_profiler.possibleTransition(Directory_State_MS_D, Directory_Event_PUTS_NotLast);
    m_profiler.possibleTransition(Directory_State_MS_D, Directory_Event_PUTM_NotOwner);
    m_profiler.possibleTransition(Directory_State_MS_D, Directory_Event_PUTM_Owner);
}
int
Directory_Controller::getNumControllers()
{
    return m_num_controllers;
}

MessageBuffer*
Directory_Controller::getMandatoryQueue() const
{
    return NULL;
}

Sequencer*
Directory_Controller::getSequencer() const
{
    return NULL;
}

const int &
Directory_Controller::getVersion() const
{
    return m_version;
}

const string
Directory_Controller::toString() const
{
    return "Directory_Controller";
}

const string
Directory_Controller::getName() const
{
    return m_name;
}

void
Directory_Controller::stallBuffer(MessageBuffer* buf, Address addr)
{
    if (m_waiting_buffers.count(addr) == 0) {
        MsgVecType* msgVec = new MsgVecType;
        msgVec->resize(m_max_in_port_rank, NULL);
        m_waiting_buffers[addr] = msgVec;
    }
    (*(m_waiting_buffers[addr]))[m_cur_in_port_rank] = buf;
}

void
Directory_Controller::wakeUpBuffers(Address addr)
{
    if (m_waiting_buffers.count(addr) > 0) {
        //
        // Wake up all possible lower rank (i.e. lower priority) buffers that could
        // be waiting on this message.
        //
        for (int in_port_rank = m_cur_in_port_rank - 1;
             in_port_rank >= 0;
             in_port_rank--) {
            if ((*(m_waiting_buffers[addr]))[in_port_rank] != NULL) {
                (*(m_waiting_buffers[addr]))[in_port_rank]->reanalyzeMessages(addr);
            }
        }
        delete m_waiting_buffers[addr];
        m_waiting_buffers.erase(addr);
    }
}

void
Directory_Controller::wakeUpAllBuffers()
{
    //
    // Wake up all possible buffers that could be waiting on any message.
    //

    std::vector<MsgVecType*> wokeUpMsgVecs;
    
    if(m_waiting_buffers.size() > 0) {
        for (WaitingBufType::iterator buf_iter = m_waiting_buffers.begin();
             buf_iter != m_waiting_buffers.end();
             ++buf_iter) {
             for (MsgVecType::iterator vec_iter = buf_iter->second->begin();
                  vec_iter != buf_iter->second->end();
                  ++vec_iter) {
                  if (*vec_iter != NULL) {
                      (*vec_iter)->reanalyzeAllMessages();
                  }
             }
             wokeUpMsgVecs.push_back(buf_iter->second);
        }

        for (std::vector<MsgVecType*>::iterator wb_iter = wokeUpMsgVecs.begin();
             wb_iter != wokeUpMsgVecs.end();
             ++wb_iter) {
             delete (*wb_iter);
        }

        m_waiting_buffers.clear();
    }
}

void
Directory_Controller::blockOnQueue(Address addr, MessageBuffer* port)
{
    m_is_blocking = true;
    m_block_map[addr] = port;
}

void
Directory_Controller::unblock(Address addr)
{
    m_block_map.erase(addr);
    if (m_block_map.size() == 0) {
       m_is_blocking = false;
    }
}

void
Directory_Controller::print(ostream& out) const
{
    out << "[Directory_Controller " << m_version << "]";
}

void
Directory_Controller::printConfig(ostream& out) const
{
    out << "Directory_Controller config: " << m_name << endl;
    out << "  version: " << m_version << endl;
    map<string, string>::const_iterator it;
    for (it = m_cfg.begin(); it != m_cfg.end(); it++)
        out << "  " << it->first << ": " << it->second << endl;
}

void
Directory_Controller::printStats(ostream& out) const
{
    m_directory_ptr->printStats(out);
    m_memBuffer_ptr->printStats(out);
    if (m_version == 0) {
        s_profileDumper.dumpStats(out);
    }
}

void Directory_Controller::clearStats() {
    m_memBuffer_ptr->clearStats();
    m_profiler.clearStats();
}

// Set and Reset for tbe variable
void
Directory_Controller::set_tbe(Directory_TBE*& m_tbe_ptr, Directory_TBE* m_new_tbe)
{
  m_tbe_ptr = m_new_tbe;
}

void
Directory_Controller::unset_tbe(Directory_TBE*& m_tbe_ptr)
{
  m_tbe_ptr = NULL;
}

void
Directory_Controller::recordCacheTrace(int cntrl, CacheRecorder* tr)
{
}

// Actions
/** \brief Remove Request sharer from list */
void
Directory_Controller::kk_removeRequestSharer(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing kk_removeRequestSharer\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_Directory_requestToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
DPRINTF(RubySlicc, "MSI-dir.sm:283: remove request from sharers...");
(((*(getDirectoryEntry(addr))).m_Sharers).remove(((*in_msg_ptr)).m_Requestor));
}

}

/** \brief Add Requestor to sharers list; got reply from memory */
void
Directory_Controller::ars1_addRequestorToSharers(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing ars1_addRequestorToSharers\n");
    {
    // Declare message
    const MemoryMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const MemoryMsg *>(((*m_memBuffer_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
(((*(getDirectoryEntry(addr))).m_Sharers).add(((*in_msg_ptr)).m_OriginalRequestorMachId));
}

}

/** \brief Add Requestor to sharers list; got incoming request */
void
Directory_Controller::ars2_addRequestorToSharers(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing ars2_addRequestorToSharers\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_Directory_requestToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
(((*(getDirectoryEntry(addr))).m_Sharers).add(((*in_msg_ptr)).m_Requestor));
}

}

/** \brief Add Owner to sharers list */
void
Directory_Controller::aos_addOwnertoSharers(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing aos_addOwnertoSharers\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_Directory_requestToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
(((*(getDirectoryEntry(addr))).m_Sharers).addNetDest((*(getDirectoryEntry(addr))).m_Owner));
}

}

/** \brief Send writeback ack to requestor; triggered from incoming request */
void
Directory_Controller::a_sendWriteBackAck(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing a_sendWriteBackAck\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_Directory_requestToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
{
    RequestMsg *out_msg = new RequestMsg;
    (*out_msg).m_Address = addr;
    (*out_msg).m_Type = CoherenceRequestType_WB_ACK;
    (*out_msg).m_Requestor = m_machineID;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
    DPRINTF(RubySlicc, "MSI-dir.sm:317: Directory - forwardNetwork_out: WB_ACK for address %s  to machine %s\n", (*out_msg).m_Address, ((*in_msg_ptr)).m_Requestor);
    ((*m_Directory_forwardFromDir_ptr)).enqueue(out_msg, m_directory_latency);
}
}

}

/** \brief Send writeback ack to requestor; triggered after memory WB ack */
void
Directory_Controller::la_sendWriteBackAck(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing la_sendWriteBackAck\n");
    {
    // Declare message
    const MemoryMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const MemoryMsg *>(((*m_memBuffer_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
{
    RequestMsg *out_msg = new RequestMsg;
    (*out_msg).m_Address = addr;
    (*out_msg).m_Type = CoherenceRequestType_WB_ACK;
    (*out_msg).m_Requestor = ((*in_msg_ptr)).m_OriginalRequestorMachId;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_OriginalRequestorMachId));
    (*out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
    DPRINTF(RubySlicc, "MSI-dir.sm:330: Directory - forwardNetwork_out: WB_ACK after Memory Ack for address %s  to machine %s\n", (*out_msg).m_Address, ((*in_msg_ptr)).m_OriginalRequestorMachId);
    ((*m_Directory_forwardFromDir_ptr)).enqueue(out_msg, m_directory_latency);
}
}

}

/** \brief Clear the owner field */
void
Directory_Controller::c_clearOwner(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing c_clearOwner\n");
    (((*(getDirectoryEntry(addr))).m_Owner).clear());

}

/** \brief Clear the sharers field */
void
Directory_Controller::cs_clearSharers(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing cs_clearSharers\n");
    (((*(getDirectoryEntry(addr))).m_Sharers).clear());

}

/** \brief Send data to requestor after retrieving data block from memory */
void
Directory_Controller::d_sendData(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing d_sendData\n");
    {
    // Declare message
    const MemoryMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const MemoryMsg *>(((*m_memBuffer_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
{
    ResponseMsg *out_msg = new ResponseMsg;
    (*out_msg).m_Address = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA_FROM_DIR;
    (*out_msg).m_Sender = m_machineID;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_OriginalRequestorMachId));
    (*out_msg).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    (*out_msg).m_AckCount = (0);
    ((*m_Directory_responseFromDir_ptr)).enqueue(out_msg, 1);
}
}

}

/** \brief Send Shared data to requestor with 0 Ack Count */
void
Directory_Controller::ds_sendSharedData(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing ds_sendSharedData\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_Directory_requestToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
{
    ResponseMsg *out_msg = new ResponseMsg;
    (*out_msg).m_Address = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA_FROM_DIR;
    (*out_msg).m_Sender = m_machineID;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_DataBlk = (*(getDirectoryEntry(addr))).m_DataBlk;
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    (*out_msg).m_AckCount = (0);
    DPRINTF(RubySlicc, "MSI-dir.sm:367: Directory - responseNetwork_out: sending DATA message type for address %s  to machine %s w/ AckCount %s\n", (*out_msg).m_Address, ((*in_msg_ptr)).m_Requestor, (*out_msg).m_AckCount);
    ((*m_Directory_responseFromDir_ptr)).enqueue(out_msg, 1);
}
}

}

/** \brief Send Shared data to requestor with Ack Count */
void
Directory_Controller::ds2_sendSharedData(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing ds2_sendSharedData\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_Directory_requestToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
{
    ResponseMsg *out_msg = new ResponseMsg;
    (*out_msg).m_Address = addr;
    (*out_msg).m_Type = CoherenceResponseType_DATA_FROM_DIR;
    (*out_msg).m_Sender = m_machineID;
    (((*out_msg).m_Destination).add(((*in_msg_ptr)).m_Requestor));
    (*out_msg).m_DataBlk = (*(getDirectoryEntry(addr))).m_DataBlk;
    (*out_msg).m_MessageSize = MessageSizeType_Response_Data;
    DPRINTF(RubySlicc, "MSI-dir.sm:381: Sending Shared data for address %s; sharers_count %s - sharers list %s - AckCount Bug?!\n", (*out_msg).m_Address, (((*(getDirectoryEntry(addr))).m_Sharers).count()), (*(getDirectoryEntry(addr))).m_Sharers);
    (*out_msg).m_AckCount = ((0) - (((*(getDirectoryEntry(addr))).m_Sharers).count()));
        if ((((*(getDirectoryEntry(((*in_msg_ptr)).m_Address))).m_Sharers).isElement(((*in_msg_ptr)).m_Requestor))) {
            (*out_msg).m_AckCount = ((1) - (((*(getDirectoryEntry(addr))).m_Sharers).count()));
        }
        DPRINTF(RubySlicc, "MSI-dir.sm:387: Directory - responseNetwork_out: sending DATA message type for address %s  to machine %s w/ AckCount %s\n", (*out_msg).m_Address, ((*in_msg_ptr)).m_Requestor, (*out_msg).m_AckCount);
        ((*m_Directory_responseFromDir_ptr)).enqueue(out_msg, 1);
    }
    }

}

/** \brief The owner is now the requestor */
void
Directory_Controller::e_ownerIsRequestor(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing e_ownerIsRequestor\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_Directory_requestToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
(((*(getDirectoryEntry(addr))).m_Owner).clear());
(((*(getDirectoryEntry(addr))).m_Owner).add(((*in_msg_ptr)).m_Requestor));
}

}

/** \brief Forward request to owner */
void
Directory_Controller::f_forwardRequest(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing f_forwardRequest\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_Directory_requestToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
APPEND_TRANSITION_COMMENT(("Own: "));
APPEND_TRANSITION_COMMENT((*(getDirectoryEntry(((*in_msg_ptr)).m_Address))).m_Owner);
APPEND_TRANSITION_COMMENT(("Req: "));
APPEND_TRANSITION_COMMENT(((*in_msg_ptr)).m_Requestor);
{
    RequestMsg *out_msg = new RequestMsg;
    (*out_msg).m_Address = addr;
    (*out_msg).m_Type = ((*in_msg_ptr)).m_Type;
    (*out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
    (*out_msg).m_Destination = (*(getDirectoryEntry(((*in_msg_ptr)).m_Address))).m_Owner;
    (*out_msg).m_MessageSize = MessageSizeType_Writeback_Control;
    DPRINTF(RubySlicc, "MSI-dir.sm:411: Directory - forwardNetwork_out: forwarding message type %s for address %s  from machine %s to machine %s\n", (*out_msg).m_Type, (*out_msg).m_Address, ((*in_msg_ptr)).m_Requestor, (*out_msg).m_Destination);
    ((*m_Directory_forwardFromDir_ptr)).enqueue(out_msg, m_directory_latency);
}
}

}

/** \brief Pop incoming request queue */
void
Directory_Controller::i_popIncomingRequestQueue(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing i_popIncomingRequestQueue\n");
    (((*m_Directory_requestToDir_ptr)).dequeue());

}

/** \brief Pop incoming response queue */
void
Directory_Controller::pr_popIncomingResponseQueue(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing pr_popIncomingResponseQueue\n");
    (((*m_Directory_responseToDir_ptr)).dequeue());

}

/** \brief Write PUTM data to directory */
void
Directory_Controller::pl_writeDataToDirectory(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing pl_writeDataToDirectory\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_Directory_requestToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
(*(getDirectoryEntry(((*in_msg_ptr)).m_Address))).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
}

}

/** \brief Write data to directory */
void
Directory_Controller::pl2_writeDataToDirectory(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing pl2_writeDataToDirectory\n");
    {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_Directory_responseToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
(*(getDirectoryEntry(((*in_msg_ptr)).m_Address))).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
}

}

/** \brief Allocate TBE */
void
Directory_Controller::vv_allocateTBEFromRequestNet(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing vv_allocateTBEFromRequestNet\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_Directory_requestToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
(((*m_Directory_TBEs_ptr)).allocate(addr));
set_tbe(m_tbe_ptr, (((*m_Directory_TBEs_ptr)).lookup(addr)));;
(*m_tbe_ptr).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
}

}

/** \brief Deallocate TBE */
void
Directory_Controller::w_deallocateTBE(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing w_deallocateTBE\n");
    (((*m_Directory_TBEs_ptr)).deallocate(addr));
unset_tbe(m_tbe_ptr);;

}

/** \brief stall */
void
Directory_Controller::z_stall(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing z_stall\n");
    
}

/** \brief Queue off-chip fetch request */
void
Directory_Controller::qf_queueMemoryFetchRequest(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing qf_queueMemoryFetchRequest\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_Directory_requestToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
{
    MemoryMsg *out_msg = new MemoryMsg;
    (*out_msg).m_Address = addr;
    (*out_msg).m_Type = MemoryRequestType_MEMORY_READ;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_OriginalRequestorMachId = ((*in_msg_ptr)).m_Requestor;
    (*out_msg).m_MessageSize = ((*in_msg_ptr)).m_MessageSize;
    (*out_msg).m_DataBlk = (*(getDirectoryEntry(((*in_msg_ptr)).m_Address))).m_DataBlk;
    DPRINTF(RubySlicc, "MSI-dir.sm:463: Directory - memQueue_out: send MEMORY_READ request for address %s triggered from machine %s\n", (*out_msg).m_Address, m_machineID);
    ((*m_memBuffer_ptr)).enqueue(out_msg, 1);
}
}

}

/** \brief Queue off-chip writeback request */
void
Directory_Controller::qwt_queueMemoryWBRequest_partialTBE(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing qwt_queueMemoryWBRequest_partialTBE\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_Directory_requestToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
{
    MemoryMsg *out_msg = new MemoryMsg;
    #ifndef NDEBUG
    if (!((m_tbe_ptr != NULL))) {
        char c;
        cerr << "Runtime Error at MSI-dir.sm:471, Ruby Time: "
             << g_eventQueue_ptr->getTime() << ": "
             << "assert failure"
             << ", PID: " << getpid() << endl
             << "press return to continue." << endl;
        cin.get(c);
        abort();

    }
    #endif
    ;
    (*out_msg).m_Address = addr;
    (*out_msg).m_Type = MemoryRequestType_MEMORY_WB;
    (*out_msg).m_OriginalRequestorMachId = ((*in_msg_ptr)).m_Requestor;
    (((*out_msg).m_DataBlk).copyPartial((*m_tbe_ptr).m_DataBlk, (addressOffset((*m_tbe_ptr).m_PhysicalAddress)), (*m_tbe_ptr).m_Len));
    (*out_msg).m_MessageSize = ((*in_msg_ptr)).m_MessageSize;
    DPRINTF(RubySlicc, "MSI-dir.sm:477: Directory - memQueue_out: send partial MEMORY_WB request for address %s triggered from machine %s\n", (*out_msg).m_Address, ((*in_msg_ptr)).m_Requestor);
    ((*m_memBuffer_ptr)).enqueue(out_msg, 1);
}
}

}

/** \brief Write PUTM data to memory from requestQueue */
void
Directory_Controller::lq_queueMemoryWBRequest(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing lq_queueMemoryWBRequest\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_Directory_requestToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
{
    MemoryMsg *out_msg = new MemoryMsg;
    (*out_msg).m_Address = addr;
    (*out_msg).m_Type = MemoryRequestType_MEMORY_WB;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_OriginalRequestorMachId = ((*in_msg_ptr)).m_Requestor;
    (*out_msg).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
    (*out_msg).m_MessageSize = ((*in_msg_ptr)).m_MessageSize;
    DPRINTF(RubySlicc, "MSI-dir.sm:491: Directory - memQueue_out: send MEMORY_WB request for address %s triggered from machine %s\n", (*out_msg).m_Address, ((*in_msg_ptr)).m_Requestor);
    ((*m_memBuffer_ptr)).enqueue(out_msg, 1);
}
}

}

/** \brief Write data to memory from responseQueue */
void
Directory_Controller::lq2_queueMemoryWBRequest(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing lq2_queueMemoryWBRequest\n");
    {
    // Declare message
    const ResponseMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const ResponseMsg *>(((*m_Directory_responseToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
{
    MemoryMsg *out_msg = new MemoryMsg;
    (*out_msg).m_Address = addr;
    (*out_msg).m_Type = MemoryRequestType_MEMORY_WB;
    (*out_msg).m_Sender = m_machineID;
    (*out_msg).m_OriginalRequestorMachId = ((*in_msg_ptr)).m_Sender;
    (*out_msg).m_DataBlk = ((*in_msg_ptr)).m_DataBlk;
    (*out_msg).m_MessageSize = ((*in_msg_ptr)).m_MessageSize;
    DPRINTF(RubySlicc, "MSI-dir.sm:505: Directory - memQueue_out: send MEMORY_WB request for address %s triggered from machine %s\n", (*out_msg).m_Address, ((*in_msg_ptr)).m_Sender);
    ((*m_memBuffer_ptr)).enqueue(out_msg, 1);
}
}

}

/** \brief Pop off-chip request queue */
void
Directory_Controller::qm_popMemQueue(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing qm_popMemQueue\n");
    DPRINTF(RubySlicc, "MSI-dir.sm:511: Directory - Popping Request from memQueue\n");
(((*m_memBuffer_ptr)).dequeue());

}

/** \brief Write date to directory memory from TBE */
void
Directory_Controller::w_writeDataToDirectoryFromTBE(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing w_writeDataToDirectoryFromTBE\n");
    #ifndef NDEBUG
if (!((m_tbe_ptr != NULL))) {
    char c;
    cerr << "Runtime Error at MSI-dir.sm:516, Ruby Time: "
         << g_eventQueue_ptr->getTime() << ": "
         << "assert failure"
         << ", PID: " << getpid() << endl
         << "press return to continue." << endl;
    cin.get(c);
    abort();

}
#endif
;
(((*(getDirectoryEntry(addr))).m_DataBlk).copyPartial((*m_tbe_ptr).m_DataBlk, (addressOffset((*m_tbe_ptr).m_PhysicalAddress)), (*m_tbe_ptr).m_Len));

}

/** \brief invalidate sharers for request */
void
Directory_Controller::fwm_sendFwdInvToSharersMinusRequestor(Directory_TBE*& m_tbe_ptr, const Address& addr)
{
    DPRINTF(RubyGenerated, "executing fwm_sendFwdInvToSharersMinusRequestor\n");
    {
    // Declare message
    const RequestMsg* in_msg_ptr M5_VAR_USED;
    in_msg_ptr = dynamic_cast<const RequestMsg *>(((*m_Directory_requestToDir_ptr)).peek());
    assert(in_msg_ptr != NULL); // Check the cast result
{
    RequestMsg *out_msg = new RequestMsg;
    (*out_msg).m_Address = addr;
    (*out_msg).m_Type = CoherenceRequestType_INV;
    (*out_msg).m_Requestor = ((*in_msg_ptr)).m_Requestor;
    (*out_msg).m_Destination = (*(getDirectoryEntry(addr))).m_Sharers;
        if ((((*(getDirectoryEntry(((*in_msg_ptr)).m_Address))).m_Sharers).isElement(((*in_msg_ptr)).m_Requestor))) {
            (((*out_msg).m_Destination).remove(((*in_msg_ptr)).m_Requestor));
        }
        (*out_msg).m_MessageSize = MessageSizeType_Request_Control;
        DPRINTF(RubySlicc, "MSI-dir.sm:534: Directory - forwardNetwork_out: send INV request for address %s to Sharers %s triggered from machine %s Destinatation Cnt %s\n", (*out_msg).m_Address, (*out_msg).m_Destination, ((*in_msg_ptr)).m_Requestor, (((*out_msg).m_Destination).count()));
        ((*m_Directory_forwardFromDir_ptr)).enqueue(out_msg, m_directory_latency);
    }
    }

}

Directory_Entry*
Directory_Controller::getDirectoryEntry(const Address& param_addr)
{
Directory_Entry* dir_entry
 = static_cast<Directory_Entry *>((((*m_directory_ptr)).lookup(param_addr)))
;
    if ((dir_entry != NULL)) {
        return dir_entry;
    }
    dir_entry = static_cast<Directory_Entry *>((((*m_directory_ptr)).allocate(param_addr, new Directory_Entry)))
    ;
    return dir_entry;

}
Directory_State
Directory_Controller::getState(Directory_TBE* param_tbe, const Address& param_addr)
{
    if ((param_tbe != NULL)) {
        return (*param_tbe).m_TBEState;
    } else {
            if ((((*m_directory_ptr)).isPresent(param_addr))) {
                return (*(getDirectoryEntry(param_addr))).m_DirectoryState;
            } else {
                return Directory_State_I;
            }
        }

}
void
Directory_Controller::setState(Directory_TBE* param_tbe, const Address& param_addr, const Directory_State& param_state)
{
    if ((param_tbe != NULL)) {
        (*param_tbe).m_TBEState = param_state;
    }
        if ((((*m_directory_ptr)).isPresent(param_addr))) {
                if ((param_state == Directory_State_M)) {
                    #ifndef NDEBUG
                    if (!(((((*(getDirectoryEntry(param_addr))).m_Owner).count()) == (1)))) {
                        char c;
                        cerr << "Runtime Error at MSI-dir.sm:156, Ruby Time: "
                             << g_eventQueue_ptr->getTime() << ": "
                             << "assert failure"
                             << ", PID: " << getpid() << endl
                             << "press return to continue." << endl;
                        cin.get(c);
                        abort();

                    }
                    #endif
                    ;
                    #ifndef NDEBUG
                    if (!(((((*(getDirectoryEntry(param_addr))).m_Sharers).count()) == (0)))) {
                        char c;
                        cerr << "Runtime Error at MSI-dir.sm:157, Ruby Time: "
                             << g_eventQueue_ptr->getTime() << ": "
                             << "assert failure"
                             << ", PID: " << getpid() << endl
                             << "press return to continue." << endl;
                        cin.get(c);
                        abort();

                    }
                    #endif
                    ;
                }
                (*(getDirectoryEntry(param_addr))).m_DirectoryState = param_state;
                    if ((param_state == Directory_State_I)) {
                        #ifndef NDEBUG
                        if (!(((((*(getDirectoryEntry(param_addr))).m_Owner).count()) == (0)))) {
                            char c;
                            cerr << "Runtime Error at MSI-dir.sm:163, Ruby Time: "
                                 << g_eventQueue_ptr->getTime() << ": "
                                 << "assert failure"
                                 << ", PID: " << getpid() << endl
                                 << "press return to continue." << endl;
                            cin.get(c);
                            abort();

                        }
                        #endif
                        ;
                        #ifndef NDEBUG
                        if (!(((((*(getDirectoryEntry(param_addr))).m_Sharers).count()) == (0)))) {
                            char c;
                            cerr << "Runtime Error at MSI-dir.sm:164, Ruby Time: "
                                 << g_eventQueue_ptr->getTime() << ": "
                                 << "assert failure"
                                 << ", PID: " << getpid() << endl
                                 << "press return to continue." << endl;
                            cin.get(c);
                            abort();

                        }
                        #endif
                        ;
                        (((*m_directory_ptr)).invalidateBlock(param_addr));
                    }
                }

}
AccessPermission
Directory_Controller::getAccessPermission(const Address& param_addr)
{
Directory_TBE* tbe
 = (((*m_Directory_TBEs_ptr)).lookup(param_addr));
    if ((tbe != NULL)) {
        return (Directory_State_to_permission((*tbe).m_TBEState));
    }
        if ((((*m_directory_ptr)).isPresent(param_addr))) {
            return (Directory_State_to_permission((*(getDirectoryEntry(param_addr))).m_DirectoryState));
        }
        return AccessPermission_NotPresent;

}
void
Directory_Controller::setAccessPermission(const Address& param_addr, const Directory_State& param_state)
{
    if ((((*m_directory_ptr)).isPresent(param_addr))) {
        ((*((getDirectoryEntry(param_addr)))).changePermission((Directory_State_to_permission(param_state))));
    }

}
DataBlock&
Directory_Controller::getDataBlock(const Address& param_addr)
{
return (*(getDirectoryEntry(param_addr))).m_DataBlk;

}
