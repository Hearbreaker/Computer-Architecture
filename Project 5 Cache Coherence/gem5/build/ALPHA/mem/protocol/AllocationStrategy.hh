/** \file AllocationStrategy.hh
 *
 * Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/Type.py:442
 */

#ifndef __AllocationStrategy_HH__
#define __AllocationStrategy_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum AllocationStrategy
 *  \brief ...
 */
enum AllocationStrategy {
    AllocationStrategy_FIRST,
    AllocationStrategy_InMiddle = AllocationStrategy_FIRST, /**<  */
    AllocationStrategy_InInvCorners, /**<  */
    AllocationStrategy_InSharedSides, /**<  */
    AllocationStrategy_StaticDist, /**<  */
    AllocationStrategy_RandomBank, /**<  */
    AllocationStrategy_FrequencyBank, /**<  */
    AllocationStrategy_FrequencyBlock, /**<  */
    AllocationStrategy_LRUBlock, /**<  */
    AllocationStrategy_NUM
};

// Code to convert from a string to the enumeration
AllocationStrategy string_to_AllocationStrategy(const std::string& str);

// Code to convert state to a string
std::string AllocationStrategy_to_string(const AllocationStrategy& obj);

// Code to increment an enumeration type
AllocationStrategy &operator++(AllocationStrategy &e);
std::ostream& operator<<(std::ostream& out, const AllocationStrategy& obj);

#endif // __AllocationStrategy_HH__
