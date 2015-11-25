#ifndef plang_DivisionOperatorExpressionNode_h
#define plang_DivisionOperatorExpressionNode_h

#include <plang/def.h>
#include <plang/Token.h>
#include <plang/Operand.h>
#include <plang/Operator.h>
#include <plang/OperatorExpressionNode.h>

namespace plang {
	class DivisionOperatorExpressionNode : public OperatorExpressionNode
	{
		public:
			DivisionOperatorExpressionNode() : OperatorExpressionNode(Operator::kLeft, 3)
			{
			}

			OperandExpressionNode* execute(OperandExpressionNode* arg1, OperandExpressionNode* arg2)
			{
				return new OperandExpressionNode(arg1->_value / arg2->_value);
			}
	};
}

#endif // plang_DivisionOperatorExpressionNode_h