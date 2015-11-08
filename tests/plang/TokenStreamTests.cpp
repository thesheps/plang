#define CATCH_CONFIG_MAIN

#include <plang/plang.h>
#include <catch.hpp>
#include <plang/TokenStream.h>

#include <string>

using namespace plang;

TEST_CASE("When I parse plaintext language, then results are tokenised as separate words.", "[parsing]") {
	char buf[] = "hello world";
	TokenStream tokstr(buf);

	Token t = tokstr.getNext();
	REQUIRE(t == Token("hello"));

	t = tokstr.getNext();
	REQUIRE(t == Token("world"));
}

TEST_CASE("Parsing correctly eliminates leading/trailing whitespace", "[parsing]") {
	char buf[] = "  tok0 tok1   ";
	TokenStream tokstr(buf);
	Token t;

	t = tokstr.getNext();
	REQUIRE(t == Token("tok0"));
	t = tokstr.getNext();
	REQUIRE(t == Token("tok1"));
	t = tokstr.getNext();
	REQUIRE(t == Token::Eos);
}

TEST_CASE("Parsing correctly handles consecutive optokens", "[parsing]") {
	char buf[] = "+-";
	TokenStream tokstr(buf);
	Token t;

	t = tokstr.getNext();
	REQUIRE(t == Token("+"));
	t = tokstr.getNext();
	REQUIRE(t == Token("-"));
	t = tokstr.getNext();
	REQUIRE(t == Token::Eos);
}