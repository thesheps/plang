#ifndef plang_Expression_h
#define plang_Expression_h

#include <plang/def.h>
#include <plang/ExpressionNode.h>
#include <vector>

namespace plang {
	class Expression
	{
		public:
			virtual void evaluate();
			void Expression::addExpressionNode(ExpressionNode expressionNode);
		private:
			std::vector<ExpressionNode> _expressionNodes;
	};
}

#endif // plang_Expression_h