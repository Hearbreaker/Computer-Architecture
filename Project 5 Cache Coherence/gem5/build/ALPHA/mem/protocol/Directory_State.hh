/** \file Directory_State.hh
 *
 * Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/Type.py:442
 */

#ifndef __Directory_State_HH__
#define __Directory_State_HH__

#include <iostream>
#include <string>

#include "mem/protocol/AccessPermission.hh"

// Class definition
/** \enum Directory_State
 *  \brief Directory states
 */
enum Directory_State {
    Directory_State_FIRST,
    Directory_State_I = Directory_State_FIRST, /**< Not Present/Invalid */
    Directory_State_M, /**< Modified */
    Directory_State_S, /**< Shared data/Read_Only */
    Directory_State_MS_D, /**< Wait for Data,M->S (cache) */
    Directory_State_MS_A, /**< Wait from acknowledge, M->S (memory) */
    Directory_State_MI_A, /**< Wait from acknowledge, M->I (memory) */
    Directory_State_IS_D, /**< Wait for Data,I->S (memory) */
    Directory_State_IM_D, /**< Wait for Data,I->M (memory) */
    Directory_State_NUM
};

// Code to convert from a string to the enumeration
Directory_State string_to_Directory_State(const std::string& str);

// Code to convert state to a string
std::string Directory_State_to_string(const Directory_State& obj);

// Code to increment an enumeration type
Directory_State &operator++(Directory_State &e);

// Code to convert the current state to an access permission
AccessPermission Directory_State_to_permission(const Directory_State& obj);

std::ostream& operator<<(std::ostream& out, const Directory_State& obj);

#endif // __Directory_State_HH__
