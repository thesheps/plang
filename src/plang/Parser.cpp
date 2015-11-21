#include <cstring>
#include <iostream>

#include <plang/Parser.h>
#include <plang/TokenStream.h>
#include <plang/Expression.h>
#include <plang/QuitExpression.h>
#include <plang/ExpressionNode.h>
#include <plang/ExpressionNodeFactory.h>

using namespace plang;

Expression* Parser::parse(TokenStream tokenStream)
{
	ExpressionNodeFactory factory;
	Token tok;

	while ((tok = tokenStream.getNext()) != Token::Eos) {
		if (tok == Token(":")) {
			if ((tok = tokenStream.getNext()) != Token::Eos) {
				if (tok == Token("q")) {
					return new QuitExpression();
				}
			}
		}
		else {
			ExpressionNode e = factory.create(tok);
			return new Expression();
		}
	}
}