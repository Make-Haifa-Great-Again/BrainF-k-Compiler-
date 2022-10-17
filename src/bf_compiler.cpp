#include "bf_compiler.hpp"

#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <stdexcept>

namespace bf {

std::string BFCompiler::Compile(const std::string& a_code) const 
{
    struct Compiler {
    public:
        Compiler(const std::string& a_legalSym, std::string* a_output) 
                                                : m_count(0)
                                                , m_imbalance(0)
                                                , m_lastCommand()
                                                , m_compiled(a_output)
                                                , m_legalSym(a_legalSym) 
                                                {}

        void operator()(const char a_sym) {
            if (m_legalSym.find_first_of(a_sym) != std::string::npos) {
                if (m_count) {
                    if (a_sym == m_lastCommand) {
                        ++m_count;
                        return;
                    }
                    *m_compiled += std::to_string(m_count);
                    m_count = 0;
                }
                if (a_sym == '[' || a_sym == ']') {
                    m_imbalance += (a_sym == '[') ? 1 : -1;
                } else {
                    if (a_sym != '.' && a_sym != ',') {
                        ++m_count;
                    }
                }
                *m_compiled += a_sym;
                m_lastCommand = a_sym;
            }
        }

        ~Compiler() {
            if (m_imbalance) {
                throw std::invalid_argument("Your code is imbalanced - check parenthasis.");
            }
        }

    private:
        unsigned short m_count;
        char m_imbalance;
        char m_lastCommand;
        std::string* m_compiled;
        const std::string m_legalSym;
    };

    std::string compiled;
    std::for_each(a_code.cbegin(), a_code.cend(), Compiler{m_symbols, &compiled});
    return compiled;
}

} // bf