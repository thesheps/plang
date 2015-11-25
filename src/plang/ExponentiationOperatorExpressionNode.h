#ifndef plang_ExponentiationOperatorExpressionNode_h
#define plang_ExponentiationOperatorExpressionNode_h

#include <cmath>

#include <plang/def.h>
#include <plang/Token.h>
#include <plang/Operand.h>
#include <plang/Operator.h>
#include <plang/OperatorExpressionNode.h>

namespace plang {
	class ExponentiationOperatorExpressionNode : public OperatorExpressionNode
	{
		public:
			ExponentiationOperatorExpressionNode() : OperatorExpressionNode(Operator::kRight, 4)
			{
			}

			OperandExpressionNode* execute(OperandExpressionNode* arg1, OperandExpressionNode* arg2)
			{
				return new OperandExpressionNode(pow(arg1->_value, arg2->_value));
			}
	};
}

#endif // plang_ExponentiationOperatorExpressionNode_h