#ifndef plang_QuitExpression_h
#define plang_QuitExpression_h

#include <plang/def.h>
#include <plang/Operand.h>
#include <plang/Expression.h>
#include <plang/ExpressionNode.h>

namespace plang {
	class QuitExpression : public Expression {
		public:
			void evaluate();
	};
}

#endif // plang_QuitExpression_h