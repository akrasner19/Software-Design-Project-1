#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "expression.hpp"
#include "tokenize.hpp"
#include "interpreter_semantic_error.hpp"
#include <iostream>
#include <list>

using std::istream;
using std::list;
using std::string;

class Interpreter
{
public:
	// Default construct an Interpreter with the default environment and an empty AST
	Interpreter();

	// Given a vtscript program as a std::istream, attempt to parse into an internal AST
	// return true on success, false on failure
	bool parse(istream & expression);

	// Evaluate the current AST and return the resulting Expression
	// throws InterpreterSemanticError if a semantic error is encountered
	// the exception message string should document the nature of the semantic error 
	Expression eval();

	Expression parseHelper(list<string>& tokens, Expression& head);

	// Expression getHead();

private:
	Expression ASTHead;
};

bool isNumber(const string& s);

AtomType whatType(string token);



#endif