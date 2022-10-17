#include "bf_operations.hpp"

#include <string>

namespace bf {

namespace detail {

static inline unsigned int GraspWholeNumber(std::string::iterator& a_instruction)
{
    unsigned int num = 0;
    while (*a_instruction >= '0' && *a_instruction <= '9') {
        num *= 10;
        num += static_cast<int>(*a_instruction) - '0';
        ++a_instruction;
    }
    return num;
}

} // detail

/* Plus */

std::string::iterator& Plus::Act(std::string::iterator& a_instruction, 
                                 std::list<char>::iterator& a_memoryPoint, 
                                 std::list<char>& a_memory) const 
{
    *a_memoryPoint += detail::GraspWholeNumber(++a_instruction);
    return a_instruction;
}

/* Minus */

std::string::iterator& Minus::Act(std::string::iterator& a_instruction, 
                                  std::list<char>::iterator& a_memoryPoint, 
                                  std::list<char>& a_memory) const 
{
    *a_memoryPoint -= detail::GraspWholeNumber(++a_instruction);
    return a_instruction;
}

/* Forward */

std::string::iterator& Forward::Act(std::string::iterator& a_instruction, 
                                    std::list<char>::iterator& a_memoryPoint, 
                                    std::list<char>& a_memory) const 
{
    size_t advanceBy = detail::GraspWholeNumber(++a_instruction);
    for (size_t i = 0; i < advanceBy; ++i) {
        ++a_memoryPoint;
        if (a_memoryPoint == a_memory.end()) {
            a_memory.insert(a_memoryPoint, advanceBy - i, 0);
            a_memoryPoint = --a_memory.end();
            break;
        }
    }
    return a_instruction;
}

/* Backwards */

std::string::iterator& Backwards::Act(std::string::iterator& a_instruction, 
                                      std::list<char>::iterator& a_memoryPoint, 
                                      std::list<char>& a_memory) const 
{
    size_t retreatBy = detail::GraspWholeNumber(++a_instruction);
    for (size_t i = 0; i < retreatBy; ++i) {
        if (a_memoryPoint == a_memory.begin()) {
            a_memory.insert(a_memoryPoint, retreatBy - i, 0);
            a_memoryPoint = a_memory.begin();
            break;
        }
        --a_memoryPoint;
    }
    return a_instruction;
}

/* Open */

std::string::iterator& Open::Act(std::string::iterator& a_instruction, 
                                 std::list<char>::iterator& a_memoryPoint, 
                                 std::list<char>& a_memory) const 
{
    if (!*a_memoryPoint) {
        unsigned short openedScopes = 1;
        while (openedScopes && *a_instruction != ']') {
            ++a_instruction;
            if (*a_instruction == '[') {
                ++openedScopes;
            } else if (*a_instruction == ']') {
                --openedScopes;
            }
        }
    }
    return ++a_instruction;
}

/* Close */

std::string::iterator& Close::Act(std::string::iterator& a_instruction, 
                                  std::list<char>::iterator& a_memoryPoint, 
                                  std::list<char>& a_memory) const 
{
    unsigned short openedScopes = 1;
    while (openedScopes && *a_instruction != '[') {
        --a_instruction;
        if (*a_instruction == ']') {
            ++openedScopes;
        } else if (*a_instruction == '[') {
            --openedScopes;
        }
    }
    return a_instruction;
}

/* Print */

std::string::iterator& Print::Act(std::string::iterator& a_instruction, 
                                  std::list<char>::iterator& a_memoryPoint, 
                                  std::list<char>& a_memory) const 
{
    *m_output += *a_memoryPoint;
    return ++a_instruction;
}

/* Get */

std::string::iterator& Get::Act(std::string::iterator& a_instruction, 
                                std::list<char>::iterator& a_memoryPoint, 
                                std::list<char>& a_memory) const 
{
    *a_memoryPoint = getchar();
    return ++a_instruction;
}  

} // bf