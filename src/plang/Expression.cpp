#include <iostream>
#include <queue>
#include <stack>
#include <plang/def.h>
#include <plang/Expression.h>
#include <plang/ExpressionNode.h>

using namespace plang;

int Expression::evaluate() 
{
	int i = 0;

	while (i < _expressionNodes.size())
	{
		ExpressionNode ex = _expressionNodes[i];
	
		switch (ex.expressionType)
		{
			case ex.kTypeOperand:
				_outputQueue.push(ex);
				break;

			case ex.kTypeOperator:
				if (_operatorStack.size() > 0)
				{
					ExpressionNode e = _operatorStack.top();

					if ((ex.associativity == Operator::kLeft && ex.precedence <= e.precedence) ||
						(ex.associativity == Operator::kRight && ex.precedence < e.precedence))
					{
						_operatorStack.pop();
						ExpressionNode arg1 = _outputQueue.front();
						_outputQueue.pop();
						ExpressionNode arg2 = _outputQueue.front();
						_outputQueue.pop();
					}
				}

				_operatorStack.push(ex);
				break;
		}

		i++;
	}

	return 2;
}

void Expression::addExpressionNode(ExpressionNode expressionNode) 
{
	_expressionNodes.push_back(expressionNode);
}