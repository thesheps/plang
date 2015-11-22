#include <catch.hpp>

#include <plang/plang.h>
#include <plang/TokenStream.h>
#include <plang/ExpressionNode.h>
#include <plang/Parser.h>
#include <plang/ExpressionNodeFactory.h>

#include <string>

using namespace plang;

SCENARIO("Mathematical expression is evaluated to correct result", "[parsing][tokenisation][expressions]") {
	GIVEN("Simple addition expression") {
		char buf[] = "1 + 1";
		TokenStream tokstr(buf);
	
		WHEN("The expression is parsed") {
			Parser parser;
			Expression ex = parser.parse(tokstr);

			THEN("The result is correct") {
				int result = ex.evaluate();

				REQUIRE(result == 2);
			}
		}
	}

	GIVEN("Complicated mathematical expression (3 * 5) - 10 / 2") {
		char buf[] = "(3 * 5) - 10 / 2";
		TokenStream tokstr(buf);

		WHEN("The expression is parsed") {
			Parser parser;
			Expression ex = parser.parse(tokstr);

			THEN("The result is correct") {
				int result = ex.evaluate();

				REQUIRE(result == 10);
			}
		}
	}
}