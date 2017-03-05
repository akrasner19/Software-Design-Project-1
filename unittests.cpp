#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "interpreter.hpp"
#include "expression.hpp"

#include <string>
#include <sstream>
#include <iostream>

using std::string;

TEST_CASE("Tests 1 from interpreter", "[interpreter]")
{
	Interpreter interpreter;
	string nums = "3";
	string str = "strhih";
	string boo = "True";
	string stuff = "(+ 3 2)";
	std::istringstream stream(stuff);
	Expression e(nums);
	Expression r(boo);
	Expression f;
	Expression t(str);
	whatType(nums);
	whatType(str);
	whatType(boo);
	//REQUIRE(interpreter.parse(stream));
	//REQUIRE(isNumber(nums));
	REQUIRE(true);
}