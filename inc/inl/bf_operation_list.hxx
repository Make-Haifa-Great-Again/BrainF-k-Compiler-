#ifndef BF_OPERATION_LIST_HXX
#define BF_OPERATION_LIST_HXX

#include <map>
#include <string>
#include <algorithm>
#include "bf_command.hpp"

namespace bf {

inline BFOperationList::~BFOperationList()
{
    struct DestroyCommands {
        void operator()(std::pair<char, BFCommand*> a_pair) {
            delete a_pair.second;
        }
    };
    std::for_each(m_commands.begin(), m_commands.end(), DestroyCommands{});
}

inline bool BFOperationList::operator==(char a_symbol) const noexcept
{
    return (m_symbols.find_first_of(a_symbol) != std::string::npos);
}

inline const std::string BFOperationList::Symbols() const noexcept
{
    return std::string{m_symbols};
}

inline void BFOperationList::Add(char a_symbol, BFCommand* a_command)
{
    m_commands.insert(std::pair<char, BFCommand*>(a_symbol, a_command));
    m_symbols += a_symbol;
}

inline std::string::iterator& BFOperationList::Act(std::string::iterator& a_instruction, 
                                      std::list<char>::iterator& a_memoryPoint, 
                                      std::list<char>& a_memory)
{
    return m_commands[*a_instruction]->Act(a_instruction, a_memoryPoint, a_memory);
}

} // bf

#endif /* BF_OPERATION_LIST_HXX */