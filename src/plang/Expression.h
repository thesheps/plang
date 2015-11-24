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
			void addExpressionNode(ExpressionNode* expressionNode);
		private:
			std::queue<OperandExpressionNode*> _outputQueue;
			std::stack<OperatorExpressionNode*> _operatorStack;
			std::vector<ExpressionNode*> _expressionNodes;
	};
}

#endif // plang_Expression_h