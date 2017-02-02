/** \file Directory_State.hh
 *
 * Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/Type.py:554
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/Directory_State.hh"

using namespace std;

// Code to convert the current state to an access permission
AccessPermission Directory_State_to_permission(const Directory_State& obj)
{
    switch(obj) {
      case Directory_State_I:
        return AccessPermission_Invalid;
      case Directory_State_M:
        return AccessPermission_Read_Write;
      case Directory_State_S:
        return AccessPermission_Read_Only;
      case Directory_State_MS_D:
        return AccessPermission_Busy;
      case Directory_State_MS_A:
        return AccessPermission_Busy;
      case Directory_State_MI_A:
        return AccessPermission_Busy;
      case Directory_State_IS_D:
        return AccessPermission_Busy;
      case Directory_State_IM_D:
        return AccessPermission_Busy;
      default:
        panic("Unknown state access permission converstion for Directory_State");
    }
}

// Code for output operator
ostream&
operator<<(ostream& out, const Directory_State& obj)
{
    out << Directory_State_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
Directory_State_to_string(const Directory_State& obj)
{
    switch(obj) {
      case Directory_State_I:
        return "I";
      case Directory_State_M:
        return "M";
      case Directory_State_S:
        return "S";
      case Directory_State_MS_D:
        return "MS_D";
      case Directory_State_MS_A:
        return "MS_A";
      case Directory_State_MI_A:
        return "MI_A";
      case Directory_State_IS_D:
        return "IS_D";
      case Directory_State_IM_D:
        return "IM_D";
      default:
        panic("Invalid range for type Directory_State");
    }
}

// Code to convert from a string to the enumeration
Directory_State
string_to_Directory_State(const string& str)
{
    if (str == "I") {
        return Directory_State_I;
    } else if (str == "M") {
        return Directory_State_M;
    } else if (str == "S") {
        return Directory_State_S;
    } else if (str == "MS_D") {
        return Directory_State_MS_D;
    } else if (str == "MS_A") {
        return Directory_State_MS_A;
    } else if (str == "MI_A") {
        return Directory_State_MI_A;
    } else if (str == "IS_D") {
        return Directory_State_IS_D;
    } else if (str == "IM_D") {
        return Directory_State_IM_D;
    } else {
        panic("Invalid string conversion for %s, type Directory_State", str);
    }
}

// Code to increment an enumeration type
Directory_State&
operator++(Directory_State& e)
{
    assert(e < Directory_State_NUM);
    return e = Directory_State(e+1);
}
