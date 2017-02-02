/** \file LinkType.hh
 *
 * Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/Type.py:554
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/LinkType.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const LinkType& obj)
{
    out << LinkType_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
LinkType_to_string(const LinkType& obj)
{
    switch(obj) {
      case LinkType_RC_1500UM:
        return "RC_1500UM";
      case LinkType_RC_2500UM:
        return "RC_2500UM";
      case LinkType_TL_9000UM:
        return "TL_9000UM";
      case LinkType_TL_11000UM:
        return "TL_11000UM";
      case LinkType_TL_13000UM:
        return "TL_13000UM";
      case LinkType_NO_ENERGY:
        return "NO_ENERGY";
      case LinkType_NULL:
        return "NULL";
      default:
        panic("Invalid range for type LinkType");
    }
}

// Code to convert from a string to the enumeration
LinkType
string_to_LinkType(const string& str)
{
    if (str == "RC_1500UM") {
        return LinkType_RC_1500UM;
    } else if (str == "RC_2500UM") {
        return LinkType_RC_2500UM;
    } else if (str == "TL_9000UM") {
        return LinkType_TL_9000UM;
    } else if (str == "TL_11000UM") {
        return LinkType_TL_11000UM;
    } else if (str == "TL_13000UM") {
        return LinkType_TL_13000UM;
    } else if (str == "NO_ENERGY") {
        return LinkType_NO_ENERGY;
    } else if (str == "NULL") {
        return LinkType_NULL;
    } else {
        panic("Invalid string conversion for %s, type LinkType", str);
    }
}

// Code to increment an enumeration type
LinkType&
operator++(LinkType& e)
{
    assert(e < LinkType_NUM);
    return e = LinkType(e+1);
}
