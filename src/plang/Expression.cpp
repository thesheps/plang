#include <iostream>
#include <queue>
#include <stack>
#include <plang/def.h>
#include <plang/Expression.h>
#include <plang/ExpressionNode.h>

using namespace plang;

void Expression::evaluate() {
	for (int i=0; i<_expressionNodes.size(); i++) {
		ExpressionNode ex = _expressionNodes[i];
	
		switch (ex.type)
		{
			case ex.kTypeOperand:
				_outputQueue.push(ex);
				break;

			case ex.kTypeOperator:
				_operatorStack.push(ex);
				break;
		}
	}
}

void Expression::addExpressionNode(ExpressionNode expressionNode) {
	_expressionNodes.push_back(expressionNode);
}