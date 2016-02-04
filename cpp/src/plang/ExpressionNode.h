#ifndef plang_Expression_h
#define plang_Expression_h

#include <plang/def.h>
#include <plang/Token.h>

namespace plang {

////////////////////////////////////////////////////////////////////////////////
/// \class Operator
////////////////////////////////////////////////////////////////////////////////
class Operator
{
	friend class ExpressionNode;

public:
	enum Type
	{
		kTypeInvalid = 0,
		kTypeAdd,
		kTypeSubtract,
		kTypeCount
	};

	Type getType() const { return m_type; }

private:
	Operator(Type _type  = kTypeInvalid)
		: m_type(_type)
	{ 
		PLANG_ASSERT(m_type < kTypeCount);
	}
	
	Type m_type;

}; // class Operand

////////////////////////////////////////////////////////////////////////////////
/// \class Operand
////////////////////////////////////////////////////////////////////////////////
class Operand
{
	friend class ExpressionNode;

public:
	typedef sint64 IntType;

	enum Type
	{
		kTypeInvalid = 0,
		kTypeInt,
		kTypeCount
	};

	IntType asInt() const { PLANG_ASSERT(m_type == kTypeInt); return m_value.m_int; }

private:
	Operand(Type _type = kTypeInvalid)
		: m_type(_type)
	{ 
		PLANG_ASSERT(m_type < kTypeCount);
	}

	Operand(IntType _val)
		: m_type(kTypeInt)
	{
		m_value.m_int = _val;
	}

	union
	{
		IntType m_int;
	} m_value;
	Type m_type;

}; // class Operator


////////////////////////////////////////////////////////////////////////////////
/// \class ExpressionNode
/// Building block of an expression.
////////////////////////////////////////////////////////////////////////////////
class ExpressionNode
{
public:
	enum Type 
	{
		kTypeInvalid = 0,
		kTypeOperator,
		kTypeOperand,
		kTypeCount
	};
	
	ExpressionNode(const Token& _token);

	Type getType() const               { return m_type; }
	const Operator& asOperator() const { PLANG_ASSERT(m_type == kTypeOperator); return m_operator; }
	const Operand&  asOperand() const  { PLANG_ASSERT(m_type == kTypeOperand);  return m_operand; }

private:
	Type m_type;
	Operator m_operator;
	Operand  m_operand;

}; // class ExpressionNode

} // namespace plang

#endif // plang_Expression_h