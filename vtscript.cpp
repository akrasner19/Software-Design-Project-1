#include "environment.hpp"
#include "interpreter.hpp"
#include "tokenize.hpp"
#include "expression.hpp"

#include <iostream>
#include <fstream>
#include <list>
int main(int argc, char*argv[])
{
	std::ifstream instream(argv[1]);
	Interpreter interpreter;

	interpreter.parse(instream);
	interpreter.eval();
	return 0;
}

using std::cin;
using std::cout;