#ifndef plang_Expression_h
#define plang_Expression_h

#include <vector>
#include <queue>
#include <stack>

#include <plang/def.h>
#include <plang/ExpressionNode.h>
#include <plang/OperandExpressionNode.h>
#include <plang/OperatorExpressionNode.h>

namespace plang {
	class Expression
	{
		public:
			virtual int evaluate();
			void Expression::addExpressionNode(ExpressionNode* expressionNode)
			{
				_expressionNodes.push_back(expressionNode);
			}
		
		private:
			std::queue<OperandExpressionNode*> _outputQueue;
			std::stack<OperatorExpressionNode*> _operatorStack;
			std::vector<ExpressionNode*> _expressionNodes;

			void ApplyOperator(OperatorExpressionNode* op)
			{
				_operatorStack.pop();

				OperandExpressionNode* arg1 = _outputQueue.front();
				_outputQueue.pop();

				OperandExpressionNode* arg2 = _outputQueue.front();
				_outputQueue.pop();

				OperandExpressionNode* result = op->execute(arg1, arg2);
				_outputQueue.push(result);
			}
	};
}

#endif // plang_Expression_h