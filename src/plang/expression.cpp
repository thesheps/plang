#include <string>

#include "expression.h"
#include "token.h"

using namespace plang;

Expression::Expression()
{
}

void Expression::addToken(plang::Token token)
{
	tokens.push_back(token);
}

std::string Expression::compile()
{
	if (tokens[2].token == '+')
	{
		int op1 = tokens[0].token - '0';
		int op2 = tokens[4].token - '0';
		
		return std::to_string(op1 + op2);
	}

	return "Hello World";
}