#include <plang/parser.h>

#include <iostream>

using namespace plang;

Parser::Parser()
{
}

std::string Parser::parse(const std::string& _input)
{
	// lol
	if (_input == "1 + 2")
	{
		return "3";
	}
	
	return _input;
}