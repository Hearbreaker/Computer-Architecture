/** \file L1Cache_Event.hh
 *
 * Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/Type.py:442
 */

#ifndef __L1Cache_Event_HH__
#define __L1Cache_Event_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum L1Cache_Event
 *  \brief Cache events
 */
enum L1Cache_Event {
    L1Cache_Event_FIRST,
    L1Cache_Event_Load = L1Cache_Event_FIRST, /**< Load request from processor */
    L1Cache_Event_Ifetch, /**< Ifetch request from processor */
    L1Cache_Event_Store, /**< Store request from processor */
    L1Cache_Event_Replacement, /**< Replace L1 cache block */
    L1Cache_Event_Fwd_GetS, /**< GetS forwarded from the directory */
    L1Cache_Event_Fwd_GetM, /**< GetM forwarded from the directory */
    L1Cache_Event_Inv, /**< Invalidate request from the directory */
    L1Cache_Event_WB_Ack, /**< Ack from the directory for a writeback */
    L1Cache_Event_Inv_Ack, /**< Invalidate Ack */
    L1Cache_Event_Inv_Ack_all, /**< Last Invalidate Ack */
    L1Cache_Event_Data_from_Dir_No_Acks, /**< Data from Directory, 0 Acks */
    L1Cache_Event_Data_from_Dir_Ack_Cnt, /**< Data from Directory, along with Ack Count */
    L1Cache_Event_Data_from_Dir_Ack_Cnt_Last, /**< Data from Directory, along with Ack Count, arrive after Inv_Ack */
    L1Cache_Event_Data_from_Owner, /**< Data from remote L1 (remote Owner) */
    L1Cache_Event_NUM
};

// Code to convert from a string to the enumeration
L1Cache_Event string_to_L1Cache_Event(const std::string& str);

// Code to convert state to a string
std::string L1Cache_Event_to_string(const L1Cache_Event& obj);

// Code to increment an enumeration type
L1Cache_Event &operator++(L1Cache_Event &e);
std::ostream& operator<<(std::ostream& out, const L1Cache_Event& obj);

#endif // __L1Cache_Event_HH__
