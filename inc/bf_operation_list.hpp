#ifndef BF_OPERATION_LIST_HPP
#define BF_OPERATION_LIST_HPP

#include <map>
#include <string>
#include "bf_command.hpp"

namespace bf {

class BFOperationList {
public:
    BFOperationList() = default;
    BFOperationList(const BFOperationList& a_other) = default;
    BFOperationList& operator=(const BFOperationList& a_other) = default;
    ~BFOperationList();

    bool operator==(char a_symbol) const noexcept;

    const std::string Symbols() const noexcept;

    void Add(char a_symbol, BFCommand* a_command);

    std::string::iterator& Act(std::string::iterator& a_instruction, 
                               std::list<char>::iterator& a_memoryPoint, 
                               std::list<char>& a_memory);

private:
    std::map<char, BFCommand*> m_commands;
    std::string m_symbols;
};

} // bf

#include "bf_operation_list.hxx"

#endif /* BF_OPERATION_LIST_HPP */