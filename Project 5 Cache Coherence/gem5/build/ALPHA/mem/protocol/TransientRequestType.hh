/** \file TransientRequestType.hh
 *
 * Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/Type.py:442
 */

#ifndef __TransientRequestType_HH__
#define __TransientRequestType_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum TransientRequestType
 *  \brief ...
 */
enum TransientRequestType {
    TransientRequestType_FIRST,
    TransientRequestType_Undefined = TransientRequestType_FIRST, /**<  */
    TransientRequestType_OffChip, /**<  */
    TransientRequestType_OnChip, /**<  */
    TransientRequestType_LocalTransient, /**<  */
    TransientRequestType_NUM
};

// Code to convert from a string to the enumeration
TransientRequestType string_to_TransientRequestType(const std::string& str);

// Code to convert state to a string
std::string TransientRequestType_to_string(const TransientRequestType& obj);

// Code to increment an enumeration type
TransientRequestType &operator++(TransientRequestType &e);
std::ostream& operator<<(std::ostream& out, const TransientRequestType& obj);

#endif // __TransientRequestType_HH__
