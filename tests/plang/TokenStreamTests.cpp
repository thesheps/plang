#define CATCH_CONFIG_MAIN

#include <plang/plang.h>
#include <catch.hpp>
#include <plang/TokenStream.h>

#include <string>

using namespace plang;

SCENARIO("String expressions are tokenised", "[parsing][tokenisation]") {
	GIVEN("Plaintext sentence") {
		char buf[] = "hello world";
		TokenStream tokstr(buf);
	
		WHEN("The sentence is parsed") {
			Token t1 = tokstr.getNext();
			Token t2 = tokstr.getNext();

			THEN("The results are tokenised as separate words") {
				REQUIRE(t1 == Token("hello"));
				REQUIRE(t2 == Token("world"));
			}
		}
	}

	GIVEN("Plaintext sentence with trailing and leading white space") {
		char buf[] = "   hello world    ";
		TokenStream tokstr(buf);
	
		WHEN("The sentence is parsed") {
			Token t1 = tokstr.getNext();
			Token t2 = tokstr.getNext();

			THEN("The results are tokenised as separate words") {
				REQUIRE(t1 == Token("hello"));
				REQUIRE(t2 == Token("world"));
			}
		}
	}

	GIVEN("Mathematical expression with spaces") {
		char buf[] = "1 + 2";
		TokenStream tokstr(buf);
	
		WHEN("The sentence is parsed") {
			Token t1 = tokstr.getNext();
			Token t2 = tokstr.getNext();
			Token t3 = tokstr.getNext();

			THEN("The spaces are ignored") {
				REQUIRE(t1 == Token("1"));
				REQUIRE(t2 == Token("+"));
				REQUIRE(t3 == Token("2"));
			}
		}
	}

	GIVEN("A subtractive expression") {
		char buf[] = "100-99";
		TokenStream tokstr(buf);
	
		WHEN("The sentence is parsed") {
			Token t1 = tokstr.getNext();
			Token t2 = tokstr.getNext();
			Token t3 = tokstr.getNext();

			THEN("The operators and operands are tokenised separately") {
				REQUIRE(t1 == Token("100"));
				REQUIRE(t2 == Token("-"));
				REQUIRE(t3 == Token("99"));
			}
		}
	}

	GIVEN("A multiplicative expression") {
		char buf[] = "100*99";
		TokenStream tokstr(buf);
	
		WHEN("The sentence is parsed") {
			Token t1 = tokstr.getNext();
			Token t2 = tokstr.getNext();
			Token t3 = tokstr.getNext();

			THEN("The operators and operands are tokenised separately") {
				REQUIRE(t1 == Token("100"));
				REQUIRE(t2 == Token("*"));
				REQUIRE(t3 == Token("99"));
			}
		}
	}

	GIVEN("A divisory expression") {
		char buf[] = "100/99";
		TokenStream tokstr(buf);
	
		WHEN("The sentence is parsed") {
			Token t1 = tokstr.getNext();
			Token t2 = tokstr.getNext();
			Token t3 = tokstr.getNext();

			THEN("The operators and operands are tokenised separately") {
				REQUIRE(t1 == Token("100"));
				REQUIRE(t2 == Token("/"));
				REQUIRE(t3 == Token("99"));
			}
		}
	}

	GIVEN("Multiple consecutive optokens") {
		char buf[] = "+-";
		TokenStream tokstr(buf);
	
		WHEN("The expression is parsed") {
			Token t1 = tokstr.getNext();
			Token t2 = tokstr.getNext();

			THEN("The operands are tokenised separately") {
				REQUIRE(t1 == Token("+"));
				REQUIRE(t2 == Token("-"));
			}
		}
	}
}