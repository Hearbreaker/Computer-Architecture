/** \file SequencerRequestType.hh
 *
 * Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/Type.py:442
 */

#ifndef __SequencerRequestType_HH__
#define __SequencerRequestType_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum SequencerRequestType
 *  \brief ...
 */
enum SequencerRequestType {
    SequencerRequestType_FIRST,
    SequencerRequestType_LD = SequencerRequestType_FIRST, /**< Load */
    SequencerRequestType_ST, /**< Store */
    SequencerRequestType_NULL, /**< Invalid request type */
    SequencerRequestType_NUM
};

// Code to convert from a string to the enumeration
SequencerRequestType string_to_SequencerRequestType(const std::string& str);

// Code to convert state to a string
std::string SequencerRequestType_to_string(const SequencerRequestType& obj);

// Code to increment an enumeration type
SequencerRequestType &operator++(SequencerRequestType &e);
std::ostream& operator<<(std::ostream& out, const SequencerRequestType& obj);

#endif // __SequencerRequestType_HH__
