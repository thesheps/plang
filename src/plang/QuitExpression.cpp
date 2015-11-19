#include <iostream>
#include <plang/def.h>
#include <plang/Expression.h>
#include <plang/QuitExpression.h>

using namespace plang;

void QuitExpression::evaluate() {
	std::cout << "Test";
}