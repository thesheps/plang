#ifndef plang_Expression_h
#define plang_Expression_h

#include <plang/def.h>
#include <plang/ExpressionNode.h>
#include <plang/EndOfExpressionException.h>
#include <vector>
#include <queue>
#include <stack>

namespace plang {
	class Expression
	{
		public:
			virtual void evaluate();
			void addExpressionNode(ExpressionNode expressionNode);
		private:
			std::queue<ExpressionNode> _outputQueue;
			std::stack<ExpressionNode> _operatorStack;
			std::vector<ExpressionNode> _expressionNodes;
	};
}

#endif // plang_Expression_h