#include "environment.hpp"
#include "interpreter.hpp"
#include "tokenize.hpp"
#include "expression.hpp"

int main(int argc, char*argv[])
{
	std::ifstream instream(argv[1]);
	Interpreter interpreter;

	interpreter.parse(instream);
	interpreter.eval();

}