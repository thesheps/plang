#include <iostream>
#include <queue>
#include <stack>
#include <typeinfo>

#include <plang/def.h>
#include <plang/Expression.h>
#include <plang/ExpressionNode.h>

using namespace plang;

int Expression::evaluate() 
{
	int i = 0;

	while (i < _expressionNodes.size())
	{
		ExpressionNode* ex = _expressionNodes[i];
	
		if (ex->expressionNodeType == ex->kTypeOperand)
		{
			OperandExpressionNode* node = (OperandExpressionNode*)ex;
			_outputQueue.push(node);
		}

		else if (ex->expressionNodeType == ex->kTypeOperator)
		{
			if (_operatorStack.size() > 0)
			{
				OperatorExpressionNode* node = (OperatorExpressionNode*)ex;
				OperatorExpressionNode* op = _operatorStack.top();

				if ((node->_associativity == Operator::kLeft && node->_precedence <= op->_precedence) ||
					(node->_associativity == Operator::kRight && node->_precedence < op->_precedence))
				{
					_operatorStack.pop();
					OperandExpressionNode* arg1 = _outputQueue.front();
					_outputQueue.pop();
					OperandExpressionNode* arg2 = _outputQueue.front();
					_outputQueue.pop();

					OperandExpressionNode* result = op->execute(arg1, arg2);
					_outputQueue.push(result);
				}
			}

			_operatorStack.push((OperatorExpressionNode*)ex);
		}

		i++;
	}

	return 2;
}

void Expression::addExpressionNode(ExpressionNode* expressionNode) 
{
	_expressionNodes.push_back(expressionNode);
}