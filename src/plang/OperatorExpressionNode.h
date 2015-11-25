#ifndef plang_OperatorExpressionNode_h
#define plang_OperatorExpressionNode_h

#include <plang/def.h>
#include <plang/Token.h>
#include <plang/Operand.h>
#include <plang/Operator.h>
#include <plang/OperandExpressionNode.h>

namespace plang {
	class OperatorExpressionNode : public ExpressionNode
	{
		public:
			OperatorExpressionNode(Operator::Associativity associativity, int precedence) : ExpressionNode(kTypeOperator)
			{
				_associativity = associativity;
				_precedence = precedence;
			}

			virtual OperandExpressionNode* execute(OperandExpressionNode* arg1, OperandExpressionNode* arg2) = 0;

		Operator::Associativity _associativity;
		int _precedence;
	};
}

#endif // plang_OperatorExpressionNode_h