#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "interpreter_semantic_error.hpp"
#include <iostream>
#include <vector>

using std::istream;
using std::vector;

class Interpreter
{
public:
	// Default construct an Interpreter with the default environment and an empty AST
	Interpreter();

	// Given a vtscript program as a std::istream, attempt to parse into an internal AST
	// return true on success, false on failure
	bool parse(istream & expression) noexcept;

	// Evaluate the current AST and return the resulting Expression
	// throws InterpreterSemanticError if a semantic error is encountered
	// the exception message string should document the nature of the semantic error 
	Expression eval();

	Expression parseHelper(vector<string>& tokens, Expression& head);

	// Expression getHead();
	
private:
	Expression ASTHead;
}

#endif