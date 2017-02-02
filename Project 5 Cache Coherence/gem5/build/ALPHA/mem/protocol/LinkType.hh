/** \file LinkType.hh
 *
 * Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/Type.py:442
 */

#ifndef __LinkType_HH__
#define __LinkType_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum LinkType
 *  \brief ...
 */
enum LinkType {
    LinkType_FIRST,
    LinkType_RC_1500UM = LinkType_FIRST, /**<  */
    LinkType_RC_2500UM, /**<  */
    LinkType_TL_9000UM, /**<  */
    LinkType_TL_11000UM, /**<  */
    LinkType_TL_13000UM, /**<  */
    LinkType_NO_ENERGY, /**<  */
    LinkType_NULL, /**<  */
    LinkType_NUM
};

// Code to convert from a string to the enumeration
LinkType string_to_LinkType(const std::string& str);

// Code to convert state to a string
std::string LinkType_to_string(const LinkType& obj);

// Code to increment an enumeration type
LinkType &operator++(LinkType &e);
std::ostream& operator<<(std::ostream& out, const LinkType& obj);

#endif // __LinkType_HH__
