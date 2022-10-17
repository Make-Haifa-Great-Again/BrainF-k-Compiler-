#ifndef BF_COMPILER_HPP
#define BF_COMPILER_HPP

#include <string>

namespace bf {

class BFCompiler {
public:
    explicit BFCompiler(const std::string& a_symbols);
    BFCompiler(const BFCompiler& a_other) = default;
    BFCompiler& operator=(const BFCompiler& a_other) = default;
    ~BFCompiler() = default;

    std::string Compile(const std::string& a_code) const;
    std::string Compile(const char* a_code) const;

private:
    const std::string m_symbols;
};

} // bf

#include "bf_compiler.hxx"

#endif /* BF_COMPILER_HPP */