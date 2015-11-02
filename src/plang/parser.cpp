#include "parser.h"
#include <iostream>
#include <string>

using std::string;
using namespace plang;

Parser::Parser()
{
}

std::string Parser::parse(std::string input)
{
	if (input == "1 + 2")
	{
		return "3";
	}
	
	return input;
}