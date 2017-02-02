/** \file SearchMechanism.hh
 *
 * Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/Type.py:554
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/misc.hh"
#include "mem/protocol/SearchMechanism.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const SearchMechanism& obj)
{
    out << SearchMechanism_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
SearchMechanism_to_string(const SearchMechanism& obj)
{
    switch(obj) {
      case SearchMechanism_Perfect:
        return "Perfect";
      case SearchMechanism_PartialTag:
        return "PartialTag";
      case SearchMechanism_BloomFilter:
        return "BloomFilter";
      case SearchMechanism_Random:
        return "Random";
      case SearchMechanism_None:
        return "None";
      default:
        panic("Invalid range for type SearchMechanism");
    }
}

// Code to convert from a string to the enumeration
SearchMechanism
string_to_SearchMechanism(const string& str)
{
    if (str == "Perfect") {
        return SearchMechanism_Perfect;
    } else if (str == "PartialTag") {
        return SearchMechanism_PartialTag;
    } else if (str == "BloomFilter") {
        return SearchMechanism_BloomFilter;
    } else if (str == "Random") {
        return SearchMechanism_Random;
    } else if (str == "None") {
        return SearchMechanism_None;
    } else {
        panic("Invalid string conversion for %s, type SearchMechanism", str);
    }
}

// Code to increment an enumeration type
SearchMechanism&
operator++(SearchMechanism& e)
{
    assert(e < SearchMechanism_NUM);
    return e = SearchMechanism(e+1);
}
