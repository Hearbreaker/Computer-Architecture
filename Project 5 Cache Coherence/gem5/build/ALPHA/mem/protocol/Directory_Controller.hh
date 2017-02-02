/** \file Directory_Controller.hh
 *
 * Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/StateMachine.py:230
 * Created by slicc definition of Module "Directory protocol"
 */

#ifndef __Directory_CONTROLLER_HH__
#define __Directory_CONTROLLER_HH__

#include <iostream>
#include <sstream>
#include <string>

#include "mem/protocol/Directory_ProfileDumper.hh"
#include "mem/protocol/Directory_Profiler.hh"
#include "mem/protocol/TransitionResult.hh"
#include "mem/protocol/Types.hh"
#include "mem/ruby/common/Consumer.hh"
#include "mem/ruby/common/Global.hh"
#include "mem/ruby/slicc_interface/AbstractController.hh"
#include "params/Directory_Controller.hh"
#include "mem/protocol/MessageBuffer.hh"
#include "mem/protocol/TBETable.hh"
extern std::stringstream Directory_transitionComment;

class Directory_Controller : public AbstractController
{
// the coherence checker needs to call isBlockExclusive() and isBlockShared()
// making the Chip a friend class is an easy way to do this for now

public:
    typedef Directory_ControllerParams Params;
    Directory_Controller(const Params *p);
    static int getNumControllers();
    void init();
    MessageBuffer* getMandatoryQueue() const;
    const int & getVersion() const;
    const std::string toString() const;
    const std::string getName() const;
    void stallBuffer(MessageBuffer* buf, Address addr);
    void wakeUpBuffers(Address addr);
    void wakeUpAllBuffers();
    void initNetworkPtr(Network* net_ptr) { m_net_ptr = net_ptr; }
    void print(std::ostream& out) const;
    void printConfig(std::ostream& out) const;
    void wakeup();
    void printStats(std::ostream& out) const;
    void clearStats();
    void blockOnQueue(Address addr, MessageBuffer* port);
    void unblock(Address addr);
    void recordCacheTrace(int cntrl, CacheRecorder* tr);
    Sequencer* getSequencer() const;

private:
    DirectoryMemory* m_directory_ptr;
    MemoryControl* m_memBuffer_ptr;
    int m_directory_latency;
    bool m_send_evictions;
    int m_number_of_TBEs;

    TransitionResult doTransition(Directory_Event event,
                                  Directory_TBE* m_tbe_ptr,
                                  const Address& addr);

    TransitionResult doTransitionWorker(Directory_Event event,
                                        Directory_State state,
                                        Directory_State& next_state,
                                        Directory_TBE*& m_tbe_ptr,
                                        const Address& addr);

    std::string m_name;
    int m_transitions_per_cycle;
    int m_buffer_size;
    int m_recycle_latency;
    std::map<std::string, std::string> m_cfg;
    NodeID m_version;
    Network* m_net_ptr;
    MachineID m_machineID;
    bool m_is_blocking;
    std::map<Address, MessageBuffer*> m_block_map;
    typedef std::vector<MessageBuffer*> MsgVecType;
    typedef std::map< Address, MsgVecType* > WaitingBufType;
    WaitingBufType m_waiting_buffers;
    int m_max_in_port_rank;
    int m_cur_in_port_rank;
    static Directory_ProfileDumper s_profileDumper;
    Directory_Profiler m_profiler;
    static int m_num_controllers;

    // Internal functions
    Directory_Entry* getDirectoryEntry(const Address& param_addr);
    Directory_State getState(Directory_TBE* param_tbe, const Address& param_addr);
    void setState(Directory_TBE* param_tbe, const Address& param_addr, const Directory_State& param_state);
    AccessPermission getAccessPermission(const Address& param_addr);
    void setAccessPermission(const Address& param_addr, const Directory_State& param_state);
    DataBlock& getDataBlock(const Address& param_addr);

    // Set and Reset for tbe variable
    void set_tbe(Directory_TBE*& m_tbe_ptr, Directory_TBE* m_new_tbe);
    void unset_tbe(Directory_TBE*& m_tbe_ptr);

    // Actions
    /** \brief Remove Request sharer from list */
    void kk_removeRequestSharer(Directory_TBE*& m_tbe_ptr, const Address& addr);
    /** \brief Add Requestor to sharers list; got reply from memory */
    void ars1_addRequestorToSharers(Directory_TBE*& m_tbe_ptr, const Address& addr);
    /** \brief Add Requestor to sharers list; got incoming request */
    void ars2_addRequestorToSharers(Directory_TBE*& m_tbe_ptr, const Address& addr);
    /** \brief Add Owner to sharers list */
    void aos_addOwnertoSharers(Directory_TBE*& m_tbe_ptr, const Address& addr);
    /** \brief Send writeback ack to requestor; triggered from incoming request */
    void a_sendWriteBackAck(Directory_TBE*& m_tbe_ptr, const Address& addr);
    /** \brief Send writeback ack to requestor; triggered after memory WB ack */
    void la_sendWriteBackAck(Directory_TBE*& m_tbe_ptr, const Address& addr);
    /** \brief Clear the owner field */
    void c_clearOwner(Directory_TBE*& m_tbe_ptr, const Address& addr);
    /** \brief Clear the sharers field */
    void cs_clearSharers(Directory_TBE*& m_tbe_ptr, const Address& addr);
    /** \brief Send data to requestor after retrieving data block from memory */
    void d_sendData(Directory_TBE*& m_tbe_ptr, const Address& addr);
    /** \brief Send Shared data to requestor with 0 Ack Count */
    void ds_sendSharedData(Directory_TBE*& m_tbe_ptr, const Address& addr);
    /** \brief Send Shared data to requestor with Ack Count */
    void ds2_sendSharedData(Directory_TBE*& m_tbe_ptr, const Address& addr);
    /** \brief The owner is now the requestor */
    void e_ownerIsRequestor(Directory_TBE*& m_tbe_ptr, const Address& addr);
    /** \brief Forward request to owner */
    void f_forwardRequest(Directory_TBE*& m_tbe_ptr, const Address& addr);
    /** \brief Pop incoming request queue */
    void i_popIncomingRequestQueue(Directory_TBE*& m_tbe_ptr, const Address& addr);
    /** \brief Pop incoming response queue */
    void pr_popIncomingResponseQueue(Directory_TBE*& m_tbe_ptr, const Address& addr);
    /** \brief Write PUTM data to directory */
    void pl_writeDataToDirectory(Directory_TBE*& m_tbe_ptr, const Address& addr);
    /** \brief Write data to directory */
    void pl2_writeDataToDirectory(Directory_TBE*& m_tbe_ptr, const Address& addr);
    /** \brief Allocate TBE */
    void vv_allocateTBEFromRequestNet(Directory_TBE*& m_tbe_ptr, const Address& addr);
    /** \brief Deallocate TBE */
    void w_deallocateTBE(Directory_TBE*& m_tbe_ptr, const Address& addr);
    /** \brief stall */
    void z_stall(Directory_TBE*& m_tbe_ptr, const Address& addr);
    /** \brief Queue off-chip fetch request */
    void qf_queueMemoryFetchRequest(Directory_TBE*& m_tbe_ptr, const Address& addr);
    /** \brief Queue off-chip writeback request */
    void qwt_queueMemoryWBRequest_partialTBE(Directory_TBE*& m_tbe_ptr, const Address& addr);
    /** \brief Write PUTM data to memory from requestQueue */
    void lq_queueMemoryWBRequest(Directory_TBE*& m_tbe_ptr, const Address& addr);
    /** \brief Write data to memory from responseQueue */
    void lq2_queueMemoryWBRequest(Directory_TBE*& m_tbe_ptr, const Address& addr);
    /** \brief Pop off-chip request queue */
    void qm_popMemQueue(Directory_TBE*& m_tbe_ptr, const Address& addr);
    /** \brief Write date to directory memory from TBE */
    void w_writeDataToDirectoryFromTBE(Directory_TBE*& m_tbe_ptr, const Address& addr);
    /** \brief invalidate sharers for request */
    void fwm_sendFwdInvToSharersMinusRequestor(Directory_TBE*& m_tbe_ptr, const Address& addr);

    // Objects
    MessageBuffer* m_Directory_requestToDir_ptr;
    MessageBuffer* m_Directory_responseToDir_ptr;
    MessageBuffer* m_Directory_forwardFromDir_ptr;
    MessageBuffer* m_Directory_responseFromDir_ptr;
    TBETable<Directory_TBE>* m_Directory_TBEs_ptr;
};
#endif // __Directory_CONTROLLER_H__
