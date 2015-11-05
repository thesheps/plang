#ifndef token_h
#define token_h

namespace plang {
	class Token {
		public:
			Token();
			Token(const char* c);
			const char* token;
			bool operator== (Token t, int i);
			bool operator!= (Token t, int i);
	};
}

#endif // token_h