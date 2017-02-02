/** \file DMAResponseMsg.cc
 *
 * Auto generated C++ code started by /nfs/ug/homes-3/p/panzexi/Documents/ece552/lab5/gem5/src/mem/slicc/symbols/Type.py:402
 */

#include <iostream>

#include "mem/protocol/DMAResponseMsg.hh"

using namespace std;
/** \brief Print the state of this object */
void
DMAResponseMsg::print(ostream& out) const
{
    out << "[DMAResponseMsg: ";
    out << "Type = " << m_Type << " ";
    out << "PhysicalAddress = " << m_PhysicalAddress << " ";
    out << "LineAddress = " << m_LineAddress << " ";
    out << "Destination = " << m_Destination << " ";
    out << "DataBlk = " << m_DataBlk << " ";
    out << "MessageSize = " << m_MessageSize << " ";
    out << "Time = " << getTime() * g_eventQueue_ptr->getClock() << " ";
    out << "]";
}
