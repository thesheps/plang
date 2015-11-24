#ifndef plang_OperandExpressionNode_h
#define plang_OperandExpressionNode_h

#include <plang/def.h>
#include <plang/Token.h>
#include <plang/Operand.h>
#include <plang/Operator.h>

namespace plang {
	class OperandExpressionNode : public ExpressionNode
	{
		public:
			OperandExpressionNode(Operand::IntType value) : ExpressionNode(kTypeOperand)
			{
				_value = value;
			}

			Operand::IntType _value;
	};
}

#endif // plang_OperandExpressionNode_h