/** \file Directory_Event.hh
 *
 * Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/Type.py:442
 */

#ifndef __Directory_Event_HH__
#define __Directory_Event_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum Directory_Event
 *  \brief Directory events
 */
enum Directory_Event {
    Directory_Event_FIRST,
    Directory_Event_GETM = Directory_Event_FIRST, /**< A GETM arrives */
    Directory_Event_GETS, /**< A GETS arrives */
    Directory_Event_PUTM, /**< A PUTM arrives */
    Directory_Event_PUTM_Owner, /**< A PUTM arrives from Owner */
    Directory_Event_PUTM_NotOwner, /**< A PUTM arrives */
    Directory_Event_PUTS_NotLast, /**< A PUTS_NotLast arrives */
    Directory_Event_PUTS_Last, /**< A PUTS_Last arrives */
    Directory_Event_PUT_Ack, /**< Sending a PUT_Ack message */
    Directory_Event_Memory_Data, /**< Fetched data from memory arrives */
    Directory_Event_Memory_Ack, /**< Writeback Ack from memory arrives */
    Directory_Event_Data, /**< Data sent from L1 Cache */
    Directory_Event_NUM
};

// Code to convert from a string to the enumeration
Directory_Event string_to_Directory_Event(const std::string& str);

// Code to convert state to a string
std::string Directory_Event_to_string(const Directory_Event& obj);

// Code to increment an enumeration type
Directory_Event &operator++(Directory_Event &e);
std::ostream& operator<<(std::ostream& out, const Directory_Event& obj);

#endif // __Directory_Event_HH__
