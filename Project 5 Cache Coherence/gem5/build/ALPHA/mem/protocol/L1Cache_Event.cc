/** \file L1Cache_Event.hh
 *
 * Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/Type.py:554
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/L1Cache_Event.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const L1Cache_Event& obj)
{
    out << L1Cache_Event_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
L1Cache_Event_to_string(const L1Cache_Event& obj)
{
    switch(obj) {
      case L1Cache_Event_Load:
        return "Load";
      case L1Cache_Event_Ifetch:
        return "Ifetch";
      case L1Cache_Event_Store:
        return "Store";
      case L1Cache_Event_Replacement:
        return "Replacement";
      case L1Cache_Event_Fwd_GetS:
        return "Fwd_GetS";
      case L1Cache_Event_Fwd_GetM:
        return "Fwd_GetM";
      case L1Cache_Event_Inv:
        return "Inv";
      case L1Cache_Event_WB_Ack:
        return "WB_Ack";
      case L1Cache_Event_Inv_Ack:
        return "Inv_Ack";
      case L1Cache_Event_Inv_Ack_all:
        return "Inv_Ack_all";
      case L1Cache_Event_Data_from_Dir_No_Acks:
        return "Data_from_Dir_No_Acks";
      case L1Cache_Event_Data_from_Dir_Ack_Cnt:
        return "Data_from_Dir_Ack_Cnt";
      case L1Cache_Event_Data_from_Dir_Ack_Cnt_Last:
        return "Data_from_Dir_Ack_Cnt_Last";
      case L1Cache_Event_Data_from_Owner:
        return "Data_from_Owner";
      default:
        panic("Invalid range for type L1Cache_Event");
    }
}

// Code to convert from a string to the enumeration
L1Cache_Event
string_to_L1Cache_Event(const string& str)
{
    if (str == "Load") {
        return L1Cache_Event_Load;
    } else if (str == "Ifetch") {
        return L1Cache_Event_Ifetch;
    } else if (str == "Store") {
        return L1Cache_Event_Store;
    } else if (str == "Replacement") {
        return L1Cache_Event_Replacement;
    } else if (str == "Fwd_GetS") {
        return L1Cache_Event_Fwd_GetS;
    } else if (str == "Fwd_GetM") {
        return L1Cache_Event_Fwd_GetM;
    } else if (str == "Inv") {
        return L1Cache_Event_Inv;
    } else if (str == "WB_Ack") {
        return L1Cache_Event_WB_Ack;
    } else if (str == "Inv_Ack") {
        return L1Cache_Event_Inv_Ack;
    } else if (str == "Inv_Ack_all") {
        return L1Cache_Event_Inv_Ack_all;
    } else if (str == "Data_from_Dir_No_Acks") {
        return L1Cache_Event_Data_from_Dir_No_Acks;
    } else if (str == "Data_from_Dir_Ack_Cnt") {
        return L1Cache_Event_Data_from_Dir_Ack_Cnt;
    } else if (str == "Data_from_Dir_Ack_Cnt_Last") {
        return L1Cache_Event_Data_from_Dir_Ack_Cnt_Last;
    } else if (str == "Data_from_Owner") {
        return L1Cache_Event_Data_from_Owner;
    } else {
        panic("Invalid string conversion for %s, type L1Cache_Event", str);
    }
}

// Code to increment an enumeration type
L1Cache_Event&
operator++(L1Cache_Event& e)
{
    assert(e < L1Cache_Event_NUM);
    return e = L1Cache_Event(e+1);
}
