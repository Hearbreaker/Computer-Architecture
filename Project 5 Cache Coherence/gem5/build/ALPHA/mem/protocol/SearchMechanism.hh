/** \file SearchMechanism.hh
 *
 * Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/Type.py:442
 */

#ifndef __SearchMechanism_HH__
#define __SearchMechanism_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum SearchMechanism
 *  \brief ...
 */
enum SearchMechanism {
    SearchMechanism_FIRST,
    SearchMechanism_Perfect = SearchMechanism_FIRST, /**<  */
    SearchMechanism_PartialTag, /**<  */
    SearchMechanism_BloomFilter, /**<  */
    SearchMechanism_Random, /**<  */
    SearchMechanism_None, /**<  */
    SearchMechanism_NUM
};

// Code to convert from a string to the enumeration
SearchMechanism string_to_SearchMechanism(const std::string& str);

// Code to convert state to a string
std::string SearchMechanism_to_string(const SearchMechanism& obj);

// Code to increment an enumeration type
SearchMechanism &operator++(SearchMechanism &e);
std::ostream& operator<<(std::ostream& out, const SearchMechanism& obj);

#endif // __SearchMechanism_HH__
