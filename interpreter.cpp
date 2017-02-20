#include "interpreter.hpp"

// Default construct an Interpreter with the default environment and an empty AST
Interpreter::Interpreter()
{
	ASTHead.atom.type = NoneType;
}


// Given a vtscript program as a std::istream, attempt to parse into an internal AST
// return true on success, false on failure
bool Interpreter::parse(std::istream & expression) noexcept
{
	State state = NoBuild;
	vector<string> tokens = tokenize(expression);
	parseHelper(tokens, ASTHead);//change to deal with parse failures
	return true;
}

// Evaluate the current AST and return the resulting Expression
// throws InterpreterSemanticError if a semantic error is encountered
// the exception message string should document the nature of the semantic error 
Expression Interpreter::eval()
{
	throw InterpreterSemanticError("Error: could not evaluate expression");
}

AtomType whatType(string token)
{
	AtomType theType;
	if (isNumber(token))
	{
		theType = DoubleType;
	}
	else if (token == "True" || token == "False")
	{
		theType = BoolType;
	}
	else
	{
		theType = StringType;
	}
	return theType;
}

bool isNumber(const string& s)
{
    try
    {
        std::stod(s);
    }
    catch(...)
    {
        return false;
    }
    return true;
}

//Expression is the head of the relative thing
Expression Interpreter::parseHelper(vector<string>& tokens, Expression& head)
{
	if (tokens.front() == "(")
	{
		tokens.pop_front();
		if (head.atom.AtomType != OpType)
		{
			head.atom.AtomType = OpType;
			head.atom.string_value = tokens.front();
			tokens.pop_front();
			return parseHelper(tokens, head);
		} //make it so it splits the set up every time it hits a parenthesis into a subset that is processed by the method until it is called
		else
		{
			Expression element(tokens.front());
			element.atom.AtomType = OpType;
			tokens.pop_front();
			return parseHelper(tokens, element);
		}
	}
	else
	{
		if (tokens.front() == ")")
		{
			tokens.pop_front();
			return head;
		}
		else if (whatType(tokens.front()) == BoolType)
		{
			if (tokens.front() == "True")
			{
				Expression element(true);
				tokens.pop_front();
				head.children.push_back(element);
			}
			else if (tokens.front() == "False")
			{
				Expression element(false);
				tokens.pop_front();
				head.children.push_back(element);
			}
			return parseHelper(tokens, head);
		}
		else if (whatType(tokens.front()) == DoubleType)
		{
			Expression element(std::stod(tokens.front()));
			tokens.pop_front();
			head.children.push_back(element);
			return parseHelper(tokens, head);
		}
		else if (whatType(tokens.front()) == StringType)
		{
			Expression element(tokens.front());
			tokens.pop_front();
			head.children.push_back(element);
			return parseHelper(tokens, head);
		}
	}
}

// Expression getHead(){
// 	return ASTHead;
// }
/*
//requires that the vector being passed in starts with (
vector<string> nextSubListGen(vector<string> tokens)
{
	int i = 1;
	index = 1;
	vector<string> subList;
	while (i > 0 && index < tokens.size())
	{
		subList.push_back(tokens[index])
		if (tokens[index] == ")")
		{
			i = i - 1;
		}
		else if (tokens[index] == '(')
		{
			i = i + 1;
		}
		index++;
	}
	return subList;
}
*/