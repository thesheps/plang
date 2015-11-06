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

	Token t = tokstr.getNext();
	REQUIRE(t == Token("world"));
}

//TEST_CASE("When I parse a mathematical addition, then the results are correct.", "[parsing][maths]") {
//	Parser parser = Parser();
//	std::string output = parser.parse("1 + 2");
//	REQUIRE(output == "3");
//}

//TEST_CASE("When I parse a different mathematical addition, then the results are correct.", "[parsing][maths]") {
//	Parser parser = Parser();
//	std::string output = parser.parse("2 + 2");
//	REQUIRE(output == "4");
//}