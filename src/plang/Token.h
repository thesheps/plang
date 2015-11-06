#ifndef plang_token_h
#define plang_token_h

namespace plang {
	class Token {
		public:
			static Token Eos;

			Token(): m_tok(0) {}
			Token(const char* _tok): m_tok(_tok) {};

			bool operator==(const Token& _rhs) const;
			bool operator!=(const Token& _rhs) const { return !(*this == _rhs); }
			operator const char*() const             { return m_tok; }
		private:
			const char* m_tok;
	};
	
}

#endif // plang_token_h
