#ifndef plang_Operator_h
#define plang_Operator_h

#include <plang/def.h>
#include <plang/Token.h>

namespace plang {
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
	};
}

#endif // plang_Operator_h