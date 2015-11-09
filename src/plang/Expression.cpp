#include <plang/Expression.h>

#include <plang/def.h>
#include <plang/Token.h>

#include <cstdlib>

using namespace plang;

/*******************************************************************************

                               ExpressionNode

*******************************************************************************/

////////////////////////////////////////////////////////////////////////////////
static bool IsAlpha(char _c)
{
	return (_c >= 'A' && _c <='Z') || (_c >= 'a' && _c <= 'z'); // 2 tests? ASCII was poorly designed :(
}

////////////////////////////////////////////////////////////////////////////////
static bool IsNumeric(char _c)
{
	return _c >= '0' && _c <='9';
}

////////////////////////////////////////////////////////////////////////////////
// \todo String literals would be a special case here (they're operands
//    which start with a non-alphanumeric char '"').
// \todo Break this up into smaller functions.
// \todo Error mechanism - exceptions? Global error code?
ExpressionNode::ExpressionNode(const Token& _token)
{
	const char* t = _token;
	
	bool isAlpha   = IsAlpha(*t);
	bool isNumeric = IsNumeric(*t);
	if (isAlpha || isNumeric) { // token is a numeric literal or a symbol
		if (isNumeric) {
			m_type = kTypeOperand; // numeric literals are always operands
			long i = atol(t);
			m_operand = Operand((Operand::IntType)i);
		} else {
			// symbols may be operands (variables) or operators (functions)
		}
	} else { // token is an operator
		m_type = kTypeOperator;
		switch (*t) {
			case '+': m_operator = Operator(Operator::kTypeAdd); break;
			case '-': m_operator = Operator(Operator::kTypeSubtract); break;
			default: PLANG_ASSERT(false); break; // unsupported operator
		};
	}
}
