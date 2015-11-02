#define CATCH_CONFIG_MAIN
#include <plang/parser.h>
#include <plang/plang.h>
#include "catch.hpp"
#include <string>

using std::string;
using namespace plang;

TEST_CASE("When I parse plaintext language, then results are returned verbatim.", "[parsing]") {
	Parser parser = Parser();
	string output = parser.parse("Hello World");
	REQUIRE(output == "Hello World");
}

TEST_CASE("When I parse a mathematical addition, then the results are correct.", "[parsing][maths]") {
	Parser parser = Parser();
	string output = parser.parse("1 + 2");
	REQUIRE(output == "3");
}