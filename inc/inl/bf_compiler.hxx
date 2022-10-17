#ifndef BF_COMPILER_HXX
#define BF_COMPILER_HXX

#include <string>

namespace bf {

inline BFCompiler::BFCompiler(const std::string& a_symbols)
: m_symbols(a_symbols)
{}

inline std::string BFCompiler::Compile(const char* a_code) const
{
    return Compile(std::string{a_code});
}

} // bf

#endif /* BF_COMPILER_HXX */