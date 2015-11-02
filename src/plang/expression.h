#ifndef expression_h
#define expression_h

#include <vector>
#include <string>

#include "token.h"

namespace plang {
	class Expression {
		private:
			std::vector<plang::Token> tokens;

		public:
			Expression();
			void addToken(plang::Token token);
			std::string compile();
	};
}

#endif // expression_h