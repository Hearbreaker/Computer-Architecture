/** \file L1Cache_TBE.cc
 *
 * Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/Type.py:402
 */

#include <iostream>

#include "mem/protocol/L1Cache_TBE.hh"

using namespace std;
/** \brief Print the state of this object */
void
L1Cache_TBE::print(ostream& out) const
{
    out << "[L1Cache_TBE: ";
    out << "TBEState = " << m_TBEState << " ";
    out << "DataBlk = " << m_DataBlk << " ";
    out << "pendingAcks = " << m_pendingAcks << " ";
    out << "]";
}
