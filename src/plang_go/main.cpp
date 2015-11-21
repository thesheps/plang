#include <iostream>

#include <plang/plang.h>
#include <plang/TokenStream.h>
#include <plang/Parser.h>
#include <plang/Expression.h>
#include <plang/QuitExpression.h>
#include <plang/QuitException.h>

using namespace plang;

int main(int argc, char** argv)
{
	const int kBufSize = 1024;
	char buf[kBufSize];
	Parser parser;

	try
	{
		while (true) {
			std::cout << ">";
			std::cin.getline(buf, kBufSize);
			TokenStream tokstr(buf);
			Expression* expression = parser.parse(tokstr);

			expression->evaluate();
			std::cout << std::endl;
		}
	}
	catch (QuitException ex)
	{
		return EXIT_SUCCESS;
	}
}