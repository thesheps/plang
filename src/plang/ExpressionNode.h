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

			ExpressionNode(Type type) : expressionNodeType(type) {}

			const Type expressionNodeType;
	};

	class OperandExpressionNode : public ExpressionNode
	{
		public:
			OperandExpressionNode(Operand::IntType value) : ExpressionNode(kTypeOperand)
			{
				_value = value;
			}

			Operand::IntType _value;
	};

	class OperatorExpressionNode : public ExpressionNode
	{
		public:
			OperatorExpressionNode(Operator::Type operatorType, Operator::Associativity associativity, int precedence) 
				: ExpressionNode(kTypeOperator)
			{
				_operatorType = operatorType;
				_associativity = associativity;
				_precedence = precedence;
			}

			OperandExpressionNode* execute(OperandExpressionNode* arg1, OperandExpressionNode* arg2)
			{
				return new OperandExpressionNode(arg1->_value + arg2->_value);
			}

		Operator::Type _operatorType;
		Operator::Associativity _associativity;
		int _precedence;
	};
}

#endif // plang_ExpressionNode_h