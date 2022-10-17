#include "brain_fuck.hpp"
   
#include <string>
#include <list>
#include <iterator>
#include "bf_operation_list.hpp"
#include "bf_operations.hpp"

namespace bf {

std::string BrainFuck::Execute(std::string a_compiledCode, bool a_createNewOperationList)
{
    if (a_createNewOperationList) {
        m_operations = CreateOperationList();
    }
    m_output.clear();
    std::list<char> memory{0, 0, 0, 0, 0};
    std::list<char>::iterator memoryPoint = memory.begin();
    std::string::iterator instructionRead = a_compiledCode.begin();
    std::string::iterator stopAt = a_compiledCode.end();
    while (instructionRead != stopAt) {
        instructionRead = m_operations.Act(instructionRead, memoryPoint, memory);
    }
    return m_output;
}

BFOperationList& BrainFuck::CreateOperationList()
{
    m_operations.Add('+', new Plus{});
    m_operations.Add('-', new Minus{});
    m_operations.Add('>', new Forward{});
    m_operations.Add('<', new Backwards{});
    m_operations.Add('[', new Open{});
    m_operations.Add(']', new Close{});
    m_operations.Add('.', new Print{&m_output});
    m_operations.Add(',', new Get{});
    return m_operations;
}

} // bf