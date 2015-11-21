#include <catch.hpp>

#include <plang/plang.h>
#include <plang/TokenStream.h>
#include <plang/ExpressionNode.h>
#include <plang/Parser.h>
#include <plang/OperandExpressionNode.h>
#include <plang/OperatorExpressionNode.h>
#include <plang/ExpressionNodeFactory.h>

#include <string>

using namespace plang;

SCENARIO("Mathematical expression is evaluated to correct result", "[parsing][tokenisation][expressions]") {
	GIVEN("Mathematical expression") {
		char buf[] = "1 + 1";
		TokenStream tokstr(buf);
	
		WHEN("The expression is parsed") {
			Parser parser;
			Expression ex = parser.parse(tokstr);

			THEN("The result is correct") {

			}
		}
	}
}