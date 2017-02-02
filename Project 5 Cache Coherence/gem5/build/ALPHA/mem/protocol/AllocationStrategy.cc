/** \file AllocationStrategy.hh
 *
 * Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/Type.py:554
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/AllocationStrategy.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const AllocationStrategy& obj)
{
    out << AllocationStrategy_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
AllocationStrategy_to_string(const AllocationStrategy& obj)
{
    switch(obj) {
      case AllocationStrategy_InMiddle:
        return "InMiddle";
      case AllocationStrategy_InInvCorners:
        return "InInvCorners";
      case AllocationStrategy_InSharedSides:
        return "InSharedSides";
      case AllocationStrategy_StaticDist:
        return "StaticDist";
      case AllocationStrategy_RandomBank:
        return "RandomBank";
      case AllocationStrategy_FrequencyBank:
        return "FrequencyBank";
      case AllocationStrategy_FrequencyBlock:
        return "FrequencyBlock";
      case AllocationStrategy_LRUBlock:
        return "LRUBlock";
      default:
        panic("Invalid range for type AllocationStrategy");
    }
}

// Code to convert from a string to the enumeration
AllocationStrategy
string_to_AllocationStrategy(const string& str)
{
    if (str == "InMiddle") {
        return AllocationStrategy_InMiddle;
    } else if (str == "InInvCorners") {
        return AllocationStrategy_InInvCorners;
    } else if (str == "InSharedSides") {
        return AllocationStrategy_InSharedSides;
    } else if (str == "StaticDist") {
        return AllocationStrategy_StaticDist;
    } else if (str == "RandomBank") {
        return AllocationStrategy_RandomBank;
    } else if (str == "FrequencyBank") {
        return AllocationStrategy_FrequencyBank;
    } else if (str == "FrequencyBlock") {
        return AllocationStrategy_FrequencyBlock;
    } else if (str == "LRUBlock") {
        return AllocationStrategy_LRUBlock;
    } else {
        panic("Invalid string conversion for %s, type AllocationStrategy", str);
    }
}

// Code to increment an enumeration type
AllocationStrategy&
operator++(AllocationStrategy& e)
{
    assert(e < AllocationStrategy_NUM);
    return e = AllocationStrategy(e+1);
}
