#ifndef plang_Expression_h
#define plang_Expression_h

#include <plang/def.h>
#include <plang/ExpressionNode.h>
#include <plang/EndOfExpressionException.h>
#include <vector>

namespace plang {
	class Expression
	{
		public:
			virtual Expression evaluate();
			void addExpressionNode(ExpressionNode expressionNode);
		private:
			std::vector<ExpressionNode> _expressionNodes;
	};

	class NullExpression : public Expression 
	{
		Expression evaluate()
		{
			throw EndOfExpressionException();
		};
	};
}

#endif // plang_Expression_h