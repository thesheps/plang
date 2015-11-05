#include <plang/token.h>

#include <cstring>

using namespace plang;

bool Token::operator==(const Token& _rhs) const
{
	return strcmp(m_tok, _rhs.m_tok) == 0;
}

Token Token::Eos = Token("\0");
