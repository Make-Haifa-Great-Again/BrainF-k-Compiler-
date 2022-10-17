#ifndef BF_COMMAND_HPP
#define BF_COMMAND_HPP

#include <string>
#include <list>

namespace bf {

class BFCommand {
public:
    virtual std::string::iterator& Act(std::string::iterator& a_instruction, 
                                       std::list<char>::iterator& a_memoryPoint, 
                                       std::list<char>& a_memory) const = 0;
    virtual ~BFCommand() = default;
protected:
    BFCommand() = default;
    BFCommand(const BFCommand& a_other) = default;
    BFCommand& operator=(const BFCommand& a_other) = default;
}; 

} // bf

#endif /* BF_COMMAND_HPP */