#include "token.h"

using namespace plang;

Token::Token()
{
}

Token::Token(const char* t)
{
	token = t;
}

bool operator== (Token t, int i)
{
	return *t.token == i;
}

bool operator!= (Token t, int i)
{
	return *t.token != i;
}