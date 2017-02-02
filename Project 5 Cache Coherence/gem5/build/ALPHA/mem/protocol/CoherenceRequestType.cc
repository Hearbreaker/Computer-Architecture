/** \file CoherenceRequestType.hh
 *
 * Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/Type.py:554
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/CoherenceRequestType.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const CoherenceRequestType& obj)
{
    out << CoherenceRequestType_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
CoherenceRequestType_to_string(const CoherenceRequestType& obj)
{
    switch(obj) {
      case CoherenceRequestType_GETM:
        return "GETM";
      case CoherenceRequestType_GETS:
        return "GETS";
      case CoherenceRequestType_PUTM:
        return "PUTM";
      case CoherenceRequestType_PUTS:
        return "PUTS";
      case CoherenceRequestType_WB_ACK:
        return "WB_ACK";
      case CoherenceRequestType_WB_NACK:
        return "WB_NACK";
      case CoherenceRequestType_INV:
        return "INV";
      case CoherenceRequestType_FWD:
        return "FWD";
      default:
        panic("Invalid range for type CoherenceRequestType");
    }
}

// Code to convert from a string to the enumeration
CoherenceRequestType
string_to_CoherenceRequestType(const string& str)
{
    if (str == "GETM") {
        return CoherenceRequestType_GETM;
    } else if (str == "GETS") {
        return CoherenceRequestType_GETS;
    } else if (str == "PUTM") {
        return CoherenceRequestType_PUTM;
    } else if (str == "PUTS") {
        return CoherenceRequestType_PUTS;
    } else if (str == "WB_ACK") {
        return CoherenceRequestType_WB_ACK;
    } else if (str == "WB_NACK") {
        return CoherenceRequestType_WB_NACK;
    } else if (str == "INV") {
        return CoherenceRequestType_INV;
    } else if (str == "FWD") {
        return CoherenceRequestType_FWD;
    } else {
        panic("Invalid string conversion for %s, type CoherenceRequestType", str);
    }
}

// Code to increment an enumeration type
CoherenceRequestType&
operator++(CoherenceRequestType& e)
{
    assert(e < CoherenceRequestType_NUM);
    return e = CoherenceRequestType(e+1);
}
