#ifndef plang_Operand_h
#define plang_Operand_h

#include <plang/def.h>
#include <plang/Token.h>

namespace plang {
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
	};
};

#endif // plang_Operand_h