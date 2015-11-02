#define CATCH_CONFIG_MAIN
#include <plang/plang.h>
#include "catch.hpp"
#include <string>

using std::string;
using namespace plang;

TEST_CASE("When I parse plaintext language, then results are returned verbatim.", "[parsing]") {
	string output = plang::Parse("Hello World");
	REQUIRE(output == "Hello World");
}