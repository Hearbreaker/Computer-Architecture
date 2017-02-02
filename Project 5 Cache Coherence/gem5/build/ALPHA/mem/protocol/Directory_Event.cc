/** \file Directory_Event.hh
 *
 * Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/Type.py:554
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/Directory_Event.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const Directory_Event& obj)
{
    out << Directory_Event_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
Directory_Event_to_string(const Directory_Event& obj)
{
    switch(obj) {
      case Directory_Event_GETM:
        return "GETM";
      case Directory_Event_GETS:
        return "GETS";
      case Directory_Event_PUTM:
        return "PUTM";
      case Directory_Event_PUTM_Owner:
        return "PUTM_Owner";
      case Directory_Event_PUTM_NotOwner:
        return "PUTM_NotOwner";
      case Directory_Event_PUTS_NotLast:
        return "PUTS_NotLast";
      case Directory_Event_PUTS_Last:
        return "PUTS_Last";
      case Directory_Event_PUT_Ack:
        return "PUT_Ack";
      case Directory_Event_Memory_Data:
        return "Memory_Data";
      case Directory_Event_Memory_Ack:
        return "Memory_Ack";
      case Directory_Event_Data:
        return "Data";
      default:
        panic("Invalid range for type Directory_Event");
    }
}

// Code to convert from a string to the enumeration
Directory_Event
string_to_Directory_Event(const string& str)
{
    if (str == "GETM") {
        return Directory_Event_GETM;
    } else if (str == "GETS") {
        return Directory_Event_GETS;
    } else if (str == "PUTM") {
        return Directory_Event_PUTM;
    } else if (str == "PUTM_Owner") {
        return Directory_Event_PUTM_Owner;
    } else if (str == "PUTM_NotOwner") {
        return Directory_Event_PUTM_NotOwner;
    } else if (str == "PUTS_NotLast") {
        return Directory_Event_PUTS_NotLast;
    } else if (str == "PUTS_Last") {
        return Directory_Event_PUTS_Last;
    } else if (str == "PUT_Ack") {
        return Directory_Event_PUT_Ack;
    } else if (str == "Memory_Data") {
        return Directory_Event_Memory_Data;
    } else if (str == "Memory_Ack") {
        return Directory_Event_Memory_Ack;
    } else if (str == "Data") {
        return Directory_Event_Data;
    } else {
        panic("Invalid string conversion for %s, type Directory_Event", str);
    }
}

// Code to increment an enumeration type
Directory_Event&
operator++(Directory_Event& e)
{
    assert(e < Directory_Event_NUM);
    return e = Directory_Event(e+1);
}
