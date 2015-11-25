#ifndef plang_Operator_h
#define plang_Operator_h

#include <plang/def.h>
#include <plang/Token.h>

namespace plang {
	class Operator
	{
		friend class ExpressionNode;

		public:
			enum Associativity
			{
				kLeft,
				kRight
			};
	};
}

#endif // plang_Operator_h