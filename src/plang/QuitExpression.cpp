#include <iostream>
#include <plang/def.h>
#include <plang/Expression.h>
#include <plang/QuitExpression.h>
#include <plang/QuitException.h>

using namespace plang;

void QuitExpression::evaluate() {
	throw QuitException();
}