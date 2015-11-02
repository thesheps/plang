#include <iostream>

#include "parser.h"
#include "token.h"
#include "expression.h"

using namespace plang;

Parser::Parser()
{
}

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
}