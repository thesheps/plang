#ifndef plang_OperatorExpressionNode_h
#define plang_OperatorExpressionNode_h

#include <plang/def.h>
#include <plang/Operator.h>
#include <plang/ExpressionNode.h>

namespace plang {
	class OperatorExpressionNode : public ExpressionNode {
	public:
		OperatorExpressionNode(Operator::Type t) : m_t(t) {
			type = kTypeOperator;
		}

	private:
		Operator::Type m_t;
	};
}

#endif // plang_OperatorExpressionNode_h