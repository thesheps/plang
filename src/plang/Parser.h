#ifndef plang_parser_h
#define plang_parser_h

#include <plang/def.h>
#include <plang/Expression.h>
#include <plang/TokenStream.h>

namespace plang {
	class Parser 
	{
		public:
			Expression parse(TokenStream tokenStream);
	};
}

#endif // plang_parser_h