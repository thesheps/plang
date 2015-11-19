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
			enum Type
			{
				kTypeUnknown = 0,
				kTypeOperand,
				kTypeOperator
			};

			ExpressionNode(Type t) : type(t) {}
			const Type type;
	};
}

#endif // plang_ExpressionNode_h