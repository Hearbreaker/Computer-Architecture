/** \file TopologyType.hh
 *
 * Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/Type.py:554
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/TopologyType.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const TopologyType& obj)
{
    out << TopologyType_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
TopologyType_to_string(const TopologyType& obj)
{
    switch(obj) {
      case TopologyType_CROSSBAR:
        return "CROSSBAR";
      case TopologyType_HIERARCHICAL_SWITCH:
        return "HIERARCHICAL_SWITCH";
      case TopologyType_TORUS_2D:
        return "TORUS_2D";
      case TopologyType_PT_TO_PT:
        return "PT_TO_PT";
      case TopologyType_FILE_SPECIFIED:
        return "FILE_SPECIFIED";
      default:
        panic("Invalid range for type TopologyType");
    }
}

// Code to convert from a string to the enumeration
TopologyType
string_to_TopologyType(const string& str)
{
    if (str == "CROSSBAR") {
        return TopologyType_CROSSBAR;
    } else if (str == "HIERARCHICAL_SWITCH") {
        return TopologyType_HIERARCHICAL_SWITCH;
    } else if (str == "TORUS_2D") {
        return TopologyType_TORUS_2D;
    } else if (str == "PT_TO_PT") {
        return TopologyType_PT_TO_PT;
    } else if (str == "FILE_SPECIFIED") {
        return TopologyType_FILE_SPECIFIED;
    } else {
        panic("Invalid string conversion for %s, type TopologyType", str);
    }
}

// Code to increment an enumeration type
TopologyType&
operator++(TopologyType& e)
{
    assert(e < TopologyType_NUM);
    return e = TopologyType(e+1);
}
