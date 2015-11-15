#ifndef plang_ExpressionNodeFactory_h
#define plang_ExpressionNodeFactory_h

#include <plang/def.h>
#include <plang/Token.h>
#include <plang/ExpressionNode.h>

namespace plang {
	class ExpressionNodeFactory
	{
		public:
			ExpressionNode create(const Token& _token);
	};
}

#endif // plang_ExpressionNodeFactory_h