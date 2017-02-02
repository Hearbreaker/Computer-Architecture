/** \file CoherenceResponseType.hh
 *
 * Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/Type.py:442
 */

#ifndef __CoherenceResponseType_HH__
#define __CoherenceResponseType_HH__

#include <iostream>
#include <string>


// Class definition
/** \enum CoherenceResponseType
 *  \brief ...
 */
enum CoherenceResponseType {
    CoherenceResponseType_FIRST,
    CoherenceResponseType_ACK = CoherenceResponseType_FIRST, /**< ACKnowledgment, responder doesn't have a copy */
    CoherenceResponseType_DATA, /**< Data */
    CoherenceResponseType_DATA_EXCLUSIVE_CLEAN, /**< Data, no other processor has a copy, data is clean */
    CoherenceResponseType_DATA_EXCLUSIVE_DIRTY, /**< Data, no other processor has a copy, data is dirty */
    CoherenceResponseType_UNBLOCK, /**< Unblock */
    CoherenceResponseType_UNBLOCK_EXCLUSIVE, /**< Unblock, we're in E/M */
    CoherenceResponseType_WB_ACK, /**< Writeback ack */
    CoherenceResponseType_WRITEBACK_CLEAN, /**< Clean writeback (no data) */
    CoherenceResponseType_WRITEBACK_DIRTY, /**< Dirty writeback (contains data) */
    CoherenceResponseType_WRITEBACK, /**< Generic writeback (contains data) */
    CoherenceResponseType_DATA_FROM_DIR, /**< Data from Directory, along with Ack Count */
    CoherenceResponseType_DATA_FROM_OWNER, /**< Data from remote L1 (remote Owner) */
    CoherenceResponseType_NUM
};

// Code to convert from a string to the enumeration
CoherenceResponseType string_to_CoherenceResponseType(const std::string& str);

// Code to convert state to a string
std::string CoherenceResponseType_to_string(const CoherenceResponseType& obj);

// Code to increment an enumeration type
CoherenceResponseType &operator++(CoherenceResponseType &e);
std::ostream& operator<<(std::ostream& out, const CoherenceResponseType& obj);

#endif // __CoherenceResponseType_HH__
