#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::string;
using std::vector;
using std::istream;

vector<string> tokenize(istream& in);

#endif