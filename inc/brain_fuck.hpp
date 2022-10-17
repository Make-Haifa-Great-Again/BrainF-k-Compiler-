#ifndef BRAIN_FUCK_HPP
#define BRAIN_FUCK_HPP

#include <string>
#include <ostream>
#include "bf_operation_list.hpp"

namespace bf {

class BrainFuck {
public:
    BrainFuck();
    explicit BrainFuck(std::string a_codeFileName);
    explicit BrainFuck(const char* a_compiledCode);
    BrainFuck(const BrainFuck& a_other) = default;
    BrainFuck& operator=(const BrainFuck& a_other) = default;
    ~BrainFuck() = default;

    std::ostream& PrintOutput(std::ostream& a_outStream) const;

    std::string Execute(std::string a_compiledCode, bool a_createNewOperationList = true);
    std::string Execute(const char* a_compiledCode, bool a_createNewOperationList = true);

    BFOperationList& CreateOperationList();

private:
    std::string m_output;
    BFOperationList m_operations;
};

std::ostream& operator<<(std::ostream& a_outStream, const BrainFuck& a_bf);

} // bf

#include "brain_fuck.hxx"

#endif /* BRAIN_FUCK_HPP */