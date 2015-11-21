#ifndef plang_Expression_h
#define plang_Expression_h

#include <plang/def.h>

namespace plang {
	class Expression
	{
		public:
			virtual void evaluate();
	};
}

#endif // plang_Expression_h