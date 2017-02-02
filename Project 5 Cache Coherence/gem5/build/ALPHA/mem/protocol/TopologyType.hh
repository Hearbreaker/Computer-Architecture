/** \file TopologyType.hh
 *
 * Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/Type.py:442
 */

#ifndef __TopologyType_HH__
#define __TopologyType_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum TopologyType
 *  \brief ...
 */
enum TopologyType {
    TopologyType_FIRST,
    TopologyType_CROSSBAR = TopologyType_FIRST, /**< One node per chip, single switch crossbar */
    TopologyType_HIERARCHICAL_SWITCH, /**< One node per chip, totally ordered hierarchical tree switched network */
    TopologyType_TORUS_2D, /**< One node per chip, 2D torus */
    TopologyType_PT_TO_PT, /**< One node per chip, Point to Point Network */
    TopologyType_FILE_SPECIFIED, /**< described by the file NETWORK_FILE */
    TopologyType_NUM
};

// Code to convert from a string to the enumeration
TopologyType string_to_TopologyType(const std::string& str);

// Code to convert state to a string
std::string TopologyType_to_string(const TopologyType& obj);

// Code to increment an enumeration type
TopologyType &operator++(TopologyType &e);
std::ostream& operator<<(std::ostream& out, const TopologyType& obj);

#endif // __TopologyType_HH__
