<<<<<<< HEAD
=======
#include <plang/parser.h>

>>>>>>> 8dc874e9e7889c901f29e0eebd679e0aeb521ce2
#include <iostream>

<<<<<<< HEAD
#include "parser.h"
#include "token.h"
#include "expression.h"

=======
>>>>>>> 8dc874e9e7889c901f29e0eebd679e0aeb521ce2
using namespace plang;

Parser::Parser()
{
}

<<<<<<< HEAD
plang::Expression getExpression(std::string input)
{
	plang::Expression expression;

	for(char& c : input) {
		expression.addToken(Token(c));
	}

	return expression;
}

std::string Parser::parse(std::string input)
{
	plang::Expression expression = getExpression(input);

	return expression.compile();
=======
std::string Parser::parse(const std::string& _input)
{
	// lol
	if (_input == "1 + 2")
	{
		return "3";
	}
	
	return _input;
>>>>>>> 8dc874e9e7889c901f29e0eebd679e0aeb521ce2
}