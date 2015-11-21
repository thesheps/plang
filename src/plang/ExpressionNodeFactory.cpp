#include <cstdlib>
#include <map>

#include <plang/def.h>
#include <plang/Token.h>
#include <plang/OperandExpressionNode.h>
#include <plang/OperatorExpressionNode.h>
#include <plang/ExpressionNodeFactory.h>

using namespace plang;

static bool IsAlpha(char _c)
{
	return (_c >= 'A' && _c <='Z') || (_c >= 'a' && _c <= 'z');
}

static bool IsNumeric(char _c)
{
	return _c >= '0' && _c <='9';
}

static std::map<char, OperatorExpressionNode> Operators =
{
	{ '+', OperatorExpressionNode(Operator::kTypeAdd) },
	{ '-', OperatorExpressionNode(Operator::kTypeSubtract) },
	{ '*', OperatorExpressionNode(Operator::kTypeMultiply) },
	{ '/', OperatorExpressionNode(Operator::kTypeDivide) }
};

// \todo String literals would be a special case here (they're operands
//    which start with a non-alphanumeric char '"').
// \todo Error mechanism - exceptions? Global error code?
ExpressionNode ExpressionNodeFactory::create(const Token& _token)
{
	const char* t = _token;
	bool isAlpha   = IsAlpha(*t);
	bool isNumeric = IsNumeric(*t);
	
	if (isAlpha || isNumeric) { // token is a numeric literal or a symbol
		if (isNumeric) {
			long i = atol(t);
			return OperandExpressionNode((Operand::IntType)i);
		}
		else {
		}
	} else { // token is an operator
		return Operators[*t];
	}
}