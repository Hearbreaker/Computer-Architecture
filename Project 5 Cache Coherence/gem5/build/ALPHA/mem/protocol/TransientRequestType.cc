/** \file TransientRequestType.hh
 *
 * Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/Type.py:554
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/TransientRequestType.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const TransientRequestType& obj)
{
    out << TransientRequestType_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
TransientRequestType_to_string(const TransientRequestType& obj)
{
    switch(obj) {
      case TransientRequestType_Undefined:
        return "Undefined";
      case TransientRequestType_OffChip:
        return "OffChip";
      case TransientRequestType_OnChip:
        return "OnChip";
      case TransientRequestType_LocalTransient:
        return "LocalTransient";
      default:
        panic("Invalid range for type TransientRequestType");
    }
}

// Code to convert from a string to the enumeration
TransientRequestType
string_to_TransientRequestType(const string& str)
{
    if (str == "Undefined") {
        return TransientRequestType_Undefined;
    } else if (str == "OffChip") {
        return TransientRequestType_OffChip;
    } else if (str == "OnChip") {
        return TransientRequestType_OnChip;
    } else if (str == "LocalTransient") {
        return TransientRequestType_LocalTransient;
    } else {
        panic("Invalid string conversion for %s, type TransientRequestType", str);
    }
}

// Code to increment an enumeration type
TransientRequestType&
operator++(TransientRequestType& e)
{
    assert(e < TransientRequestType_NUM);
    return e = TransientRequestType(e+1);
}
