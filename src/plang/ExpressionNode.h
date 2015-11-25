#ifndef plang_ExpressionNode_h
#define plang_ExpressionNode_h

#include <plang/def.h>
#include <plang/Token.h>
#include <plang/Operand.h>
#include <plang/Operator.h>

namespace plang {
	class ExpressionNode
	{
		public:
			enum ExpressionNodeType
			{
				kTypeUnknown = 0,
				kTypeOperand = 1,
				kTypeOperator = 2
			};

			ExpressionNode(ExpressionNodeType type) : expressionNodeType(type) {}

			const ExpressionNodeType expressionNodeType;
	};
}

#endif // plang_ExpressionNode_h