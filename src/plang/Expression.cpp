#include <iostream>
#include <plang/def.h>
#include <plang/Expression.h>
#include <plang/ExpressionNode.h>

using namespace plang;

Expression Expression::evaluate() {
	std::cout << "Evaluating Expression...";

	for (int i=0; i<_expressionNodes.size(); i++) {
		ExpressionNode ex = _expressionNodes[i];
		std::cout << ex.type;
	}

	return NullExpression();
}

void Expression::addExpressionNode(ExpressionNode expressionNode) {
	_expressionNodes.push_back(expressionNode);
}