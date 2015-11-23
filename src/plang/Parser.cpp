#include <cstring>
#include <iostream>

#include <plang/Parser.h>
#include <plang/TokenStream.h>
#include <plang/Expression.h>
#include <plang/QuitException.h>
#include <plang/ExpressionNode.h>
#include <plang/ExpressionNodeFactory.h>

using namespace plang;

Expression Parser::parse(TokenStream tokenStream)
{
	Expression expression = Expression();
	ExpressionNodeFactory factory;
	Token tok;

	while ((tok = tokenStream.getNext()) != Token::Eos) {
		if (tok == Token(":")) {
			if ((tok = tokenStream.getNext()) != Token::Eos) {
				if (tok == Token("q")) {
					throw QuitException();
				}
			}
		}
		else {
			ExpressionNode* ex = factory.create(tok);
			expression.addExpressionNode(ex);
		}
	}

	return expression;
}