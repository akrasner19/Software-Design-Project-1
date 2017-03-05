#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include "expression.hpp"
#include "interpreter_semantic_error.hpp"


using std::string;
using std::map;
using std::cerr;
using std::endl;

typedef void (*fcp) (Expression&);

void addExp(Expression& exp);
void subExp(Expression& exp);
void multExp(Expression& exp);
void divExp(Expression& exp);
void eqExp(Expression& exp);
void geqExp(Expression& exp);
void leqExp(Expression& exp);
void ltExp(Expression& exp);
void gtExp(Expression& exp);
void andExp(Expression& exp);
void orExp(Expression& exp);
void notExp(Expression& exp);

void fillMap(map<string,fcp>& funcMap);

#endif