#include <cstdlib>

#include <plang/def.h>
#include <plang/Token.h>
#include <plang/OperandExpressionNode.h>
#include <plang/OperatorExpressionNode.h>
#include <plang/ExpressionNodeFactory.h>

using namespace plang;

static bool IsAlpha(char _c)
{
	return (_c >= 'A' && _c <='Z') || (_c >= 'a' && _c <= 'z'); // 2 tests? ASCII was poorly designed :(
}

static bool IsNumeric(char _c)
{
	return _c >= '0' && _c <='9';
}

// \todo String literals would be a special case here (they're operands
//    which start with a non-alphanumeric char '"').
// \todo Break this up into smaller functions.
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
			// symbols may be operands (variables) or operators (functions)
		}
	} else { // token is an operator
		switch (*t) {
			case '+': return OperatorExpressionNode(Operator::kTypeAdd); break;
			case '-': return OperatorExpressionNode(Operator::kTypeSubtract); break;
			default: PLANG_ASSERT(false); break; // unsupported operator
		};
	}
}