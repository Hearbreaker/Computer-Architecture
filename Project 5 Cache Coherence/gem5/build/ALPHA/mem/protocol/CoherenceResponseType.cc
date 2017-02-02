/** \file CoherenceResponseType.hh
 *
 * Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/Type.py:554
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/CoherenceResponseType.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const CoherenceResponseType& obj)
{
    out << CoherenceResponseType_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
CoherenceResponseType_to_string(const CoherenceResponseType& obj)
{
    switch(obj) {
      case CoherenceResponseType_ACK:
        return "ACK";
      case CoherenceResponseType_DATA:
        return "DATA";
      case CoherenceResponseType_DATA_EXCLUSIVE_CLEAN:
        return "DATA_EXCLUSIVE_CLEAN";
      case CoherenceResponseType_DATA_EXCLUSIVE_DIRTY:
        return "DATA_EXCLUSIVE_DIRTY";
      case CoherenceResponseType_UNBLOCK:
        return "UNBLOCK";
      case CoherenceResponseType_UNBLOCK_EXCLUSIVE:
        return "UNBLOCK_EXCLUSIVE";
      case CoherenceResponseType_WB_ACK:
        return "WB_ACK";
      case CoherenceResponseType_WRITEBACK_CLEAN:
        return "WRITEBACK_CLEAN";
      case CoherenceResponseType_WRITEBACK_DIRTY:
        return "WRITEBACK_DIRTY";
      case CoherenceResponseType_WRITEBACK:
        return "WRITEBACK";
      case CoherenceResponseType_DATA_FROM_DIR:
        return "DATA_FROM_DIR";
      case CoherenceResponseType_DATA_FROM_OWNER:
        return "DATA_FROM_OWNER";
      default:
        panic("Invalid range for type CoherenceResponseType");
    }
}

// Code to convert from a string to the enumeration
CoherenceResponseType
string_to_CoherenceResponseType(const string& str)
{
    if (str == "ACK") {
        return CoherenceResponseType_ACK;
    } else if (str == "DATA") {
        return CoherenceResponseType_DATA;
    } else if (str == "DATA_EXCLUSIVE_CLEAN") {
        return CoherenceResponseType_DATA_EXCLUSIVE_CLEAN;
    } else if (str == "DATA_EXCLUSIVE_DIRTY") {
        return CoherenceResponseType_DATA_EXCLUSIVE_DIRTY;
    } else if (str == "UNBLOCK") {
        return CoherenceResponseType_UNBLOCK;
    } else if (str == "UNBLOCK_EXCLUSIVE") {
        return CoherenceResponseType_UNBLOCK_EXCLUSIVE;
    } else if (str == "WB_ACK") {
        return CoherenceResponseType_WB_ACK;
    } else if (str == "WRITEBACK_CLEAN") {
        return CoherenceResponseType_WRITEBACK_CLEAN;
    } else if (str == "WRITEBACK_DIRTY") {
        return CoherenceResponseType_WRITEBACK_DIRTY;
    } else if (str == "WRITEBACK") {
        return CoherenceResponseType_WRITEBACK;
    } else if (str == "DATA_FROM_DIR") {
        return CoherenceResponseType_DATA_FROM_DIR;
    } else if (str == "DATA_FROM_OWNER") {
        return CoherenceResponseType_DATA_FROM_OWNER;
    } else {
        panic("Invalid string conversion for %s, type CoherenceResponseType", str);
    }
}

// Code to increment an enumeration type
CoherenceResponseType&
operator++(CoherenceResponseType& e)
{
    assert(e < CoherenceResponseType_NUM);
    return e = CoherenceResponseType(e+1);
}
