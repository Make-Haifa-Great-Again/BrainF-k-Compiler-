#ifndef BRAIN_FUCK_HXX
#define BRAIN_FUCK_HXX

#include <ostream>
#include <fstream>
#include <sstream>
#include <string>
#include "bf_operation_list.hpp"
#include "bf_compiler.hpp"

namespace bf {

static const char DEFAULT_OUTPUT[] = "Couldn't find code to execute\n";

inline BrainFuck::BrainFuck()
: m_output(DEFAULT_OUTPUT)
, m_operations()
{}

inline BrainFuck::BrainFuck(std::string a_codeFileName)
: m_output()
, m_operations()
{
    std::ifstream read{a_codeFileName};
    std::stringstream code;
    code << read.rdbuf();
    m_operations = CreateOperationList();
    std::string compiled = BFCompiler{m_operations.Symbols()}.Compile(code.str());
    Execute(compiled, false);
}

inline BrainFuck::BrainFuck(const char* a_compiledCode)
: m_output()
, m_operations()
{
    Execute(a_compiledCode);
}

inline std::string BrainFuck::Execute(const char* a_compiledCode, bool a_createNewOperationList)
{
    return Execute(std::string{a_compiledCode}, a_createNewOperationList);
}

inline std::ostream& BrainFuck::PrintOutput(std::ostream& a_outStream) const
{
    return a_outStream << m_output;
}

inline std::ostream& operator<<(std::ostream& a_outStream, const BrainFuck& a_bf)
{
    return a_bf.PrintOutput(a_outStream);
}

} // bf

#endif /* BRAIN_FUCK_HXX */