/** \file L1Cache_State.hh
 *
 * Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/Type.py:554
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/L1Cache_State.hh"

using namespace std;

// Code to convert the current state to an access permission
AccessPermission L1Cache_State_to_permission(const L1Cache_State& obj)
{
    switch(obj) {
      case L1Cache_State_I:
        return AccessPermission_Invalid;
      case L1Cache_State_S:
        return AccessPermission_Read_Only;
      case L1Cache_State_M:
        return AccessPermission_Read_Write;
      case L1Cache_State_IS_D:
        return AccessPermission_Busy;
      case L1Cache_State_IM_AD:
        return AccessPermission_Busy;
      case L1Cache_State_IM_A:
        return AccessPermission_Busy;
      case L1Cache_State_SM_AD:
        return AccessPermission_Busy;
      case L1Cache_State_SM_A:
        return AccessPermission_Busy;
      case L1Cache_State_MI_A:
        return AccessPermission_Busy;
      case L1Cache_State_SI_A:
        return AccessPermission_Busy;
      case L1Cache_State_II_A:
        return AccessPermission_Busy;
      default:
        panic("Unknown state access permission converstion for L1Cache_State");
    }
}

// Code for output operator
ostream&
operator<<(ostream& out, const L1Cache_State& obj)
{
    out << L1Cache_State_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
L1Cache_State_to_string(const L1Cache_State& obj)
{
    switch(obj) {
      case L1Cache_State_I:
        return "I";
      case L1Cache_State_S:
        return "S";
      case L1Cache_State_M:
        return "M";
      case L1Cache_State_IS_D:
        return "IS_D";
      case L1Cache_State_IM_AD:
        return "IM_AD";
      case L1Cache_State_IM_A:
        return "IM_A";
      case L1Cache_State_SM_AD:
        return "SM_AD";
      case L1Cache_State_SM_A:
        return "SM_A";
      case L1Cache_State_MI_A:
        return "MI_A";
      case L1Cache_State_SI_A:
        return "SI_A";
      case L1Cache_State_II_A:
        return "II_A";
      default:
        panic("Invalid range for type L1Cache_State");
    }
}

// Code to convert from a string to the enumeration
L1Cache_State
string_to_L1Cache_State(const string& str)
{
    if (str == "I") {
        return L1Cache_State_I;
    } else if (str == "S") {
        return L1Cache_State_S;
    } else if (str == "M") {
        return L1Cache_State_M;
    } else if (str == "IS_D") {
        return L1Cache_State_IS_D;
    } else if (str == "IM_AD") {
        return L1Cache_State_IM_AD;
    } else if (str == "IM_A") {
        return L1Cache_State_IM_A;
    } else if (str == "SM_AD") {
        return L1Cache_State_SM_AD;
    } else if (str == "SM_A") {
        return L1Cache_State_SM_A;
    } else if (str == "MI_A") {
        return L1Cache_State_MI_A;
    } else if (str == "SI_A") {
        return L1Cache_State_SI_A;
    } else if (str == "II_A") {
        return L1Cache_State_II_A;
    } else {
        panic("Invalid string conversion for %s, type L1Cache_State", str);
    }
}

// Code to increment an enumeration type
L1Cache_State&
operator++(L1Cache_State& e)
{
    assert(e < L1Cache_State_NUM);
    return e = L1Cache_State(e+1);
}
