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