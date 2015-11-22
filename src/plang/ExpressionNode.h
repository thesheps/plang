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
				kTypeOperand = 1,
				kTypeOperator = 2
			};

			ExpressionNode() : expressionType(kTypeUnknown)
			{
			}

			ExpressionNode(Operand::IntType i) : expressionType(kTypeOperand)
			{
				m_i = i;
			}

			ExpressionNode(Operator::Type t, Operator::Associativity a, int p) : expressionType(kTypeOperator)
			{
				operatorType = t;
				associativity = a;
				precedence = p;
			}

			const Type expressionType;
			Operand::IntType m_i;
			Operator::Type operatorType;
			Operator::Associativity associativity;
			int precedence;
	};
}

#endif // plang_ExpressionNode_h