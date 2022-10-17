#ifndef BF_OPERATIONS_HPP
#define BF_OPERATIONS_HPP

#include <string>
#include "bf_command.hpp"

namespace bf {

class Plus : public BFCommand {
public:
    Plus() = default;
    Plus(const Plus& a_other) = default;
    Plus& operator=(const Plus& a_other) = default;
    ~Plus() = default;

    std::string::iterator& Act(std::string::iterator& a_instruction, 
                                       std::list<char>::iterator& a_memoryPoint, 
                                       std::list<char>& a_memory) const override;
};

class Minus : public BFCommand {
public:
    Minus() = default;
    Minus(const Minus& a_other) = default;
    Minus& operator=(const Minus& a_other) = default;
    ~Minus() = default;

    std::string::iterator& Act(std::string::iterator& a_instruction, 
                                       std::list<char>::iterator& a_memoryPoint, 
                                       std::list<char>& a_memory) const override;
};

class Forward : public BFCommand {
public:
    Forward() = default;
    Forward(const Forward& a_other) = default;
    Forward& operator=(const Forward& a_other) = default;
    ~Forward() = default;

    std::string::iterator& Act(std::string::iterator& a_instruction, 
                                       std::list<char>::iterator& a_memoryPoint, 
                                       std::list<char>& a_memory) const override;
};

class Backwards : public BFCommand {
public:
    Backwards() = default;
    Backwards(const Backwards& a_other) = default;
    Backwards& operator=(const Backwards& a_other) = default;
    ~Backwards() = default;

    std::string::iterator& Act(std::string::iterator& a_instruction, 
                                       std::list<char>::iterator& a_memoryPoint, 
                                       std::list<char>& a_memory) const override;
};

class Open : public BFCommand {
public:
    Open() = default;
    Open(const Open& a_other) = default;
    Open& operator=(const Open& a_other) = default;
    ~Open() = default;

    std::string::iterator& Act(std::string::iterator& a_instruction, 
                                       std::list<char>::iterator& a_memoryPoint, 
                                       std::list<char>& a_memory) const override;
};

class Close : public BFCommand {
public:
    Close() = default;
    Close(const Close& a_other) = default;
    Close& operator=(const Close& a_other) = default;
    ~Close() = default;

    std::string::iterator& Act(std::string::iterator& a_instruction, 
                                       std::list<char>::iterator& a_memoryPoint, 
                                       std::list<char>& a_memory) const override;
};

class Print : public BFCommand {
public:
    explicit Print(std::string* a_output);
    Print(const Print& a_other) = default;
    Print& operator=(const Print& a_other) = default;
    ~Print() = default;

    std::string::iterator& Act(std::string::iterator& a_instruction, 
                                       std::list<char>::iterator& a_memoryPoint, 
                                       std::list<char>& a_memory) const override;

private:
    std::string* m_output;
};

class Get : public BFCommand {
public:
    Get() = default;
    Get(const Get& a_other) = default;
    Get& operator=(const Get& a_other) = default;
    ~Get() = default;

    std::string::iterator& Act(std::string::iterator& a_instruction, 
                                       std::list<char>::iterator& a_memoryPoint, 
                                       std::list<char>& a_memory) const override;
};

} // bf

#include "bf_operations.hxx"

#endif /* BF_OPERATIONS_HPP */