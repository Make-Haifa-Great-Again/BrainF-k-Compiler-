#include "mu_test.h"

#include "brain_fuck.hpp"
#include "bf_compiler.hpp"

#include <string>
#include <sstream>

BEGIN_TEST(h_capital)
	using bf::BrainFuck;
	std::string output{};
	BrainFuck helloW{"+72."};
	std::stringstream output_ss{output};
	output_ss << helloW;
	TRACE(output_ss.str());
	ASSERT_EQUAL(output_ss.str(), std::string{"H"});
END_TEST

BEGIN_TEST(hello_world_from_char)
	using bf::BrainFuck;
	bf::BFCompiler compiler{std::string{"+-.,][><"}};
	std::string output, input, code = "++++++++++[>+>+++>+++++++>++++++++++<<<<-]>>>++.>+.+++++++..+++.<<++.>+++++++++++++++.>.+++.------.--------.<<+.";
	input = compiler.Compile(code);
	BrainFuck helloW{};
	output = helloW.Execute(input);
	TRACE(input);
	TRACE(output);
	ASSERT_EQUAL(output, std::string{"Hello World!"});
END_TEST

BEGIN_TEST(hello_world_from_file)
	using bf::BrainFuck;
	std::string output{}, fileName{"../../resources/brain_fuck/hello_world.bf"};
	BrainFuck helloW{fileName};
	std::stringstream output_ss{output};
	output_ss << helloW;
	TRACE(output_ss.str());
	ASSERT_EQUAL(output_ss.str(), std::string{"Hello World!"});
END_TEST

BEGIN_SUITE(Brain Fuck Compiler Tests)
	TEST(h_capital)
	TEST(hello_world_from_char)
	TEST(hello_world_from_file)
END_SUITE
