#ifndef plang_OperandExpressionNode_h
#define plang_OperandExpressionNode_h

#include <plang/def.h>
#include <plang/Operand.h>
#include <plang/ExpressionNode.h>

namespace plang {
	class OperandExpressionNode : public ExpressionNode {
	public:
		OperandExpressionNode(Operand::IntType i) : m_i(i) {
			type = kTypeOperand;
		}
	private:
		Operand::IntType m_i;
	};
}

#endif // plang_OperandExpressionNode_h