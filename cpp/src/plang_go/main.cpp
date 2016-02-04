#include <plang/plang.h>
#include <plang/Token.h>
#include <plang/TokenStream.h>
#include <plang/ExpressionNode.h>

#include <iostream>

using namespace plang;

int main(int argc, char** argv)
{
	// this is rather shitty code, just an adhoc test for the token stream
	const int kBufSize = 1024;
	char buf[kBufSize];
	while (true) {
		std::cout << ">";
		std::cin.getline(buf, kBufSize);
		TokenStream tokstr(buf);
		Token tok;
		while ((tok = tokstr.getNext()) != Token::Eos) {
			if (tok == Token(":")) {
				if ((tok = tokstr.getNext()) != Token::Eos) {
					if (tok == Token("q")) {
						goto plang_go_end;
					}
				}	
			} else {
				ExpressionNode expNode(tok);
				std::cout << tok << "_";
			}
		}
		std::cout << std::endl;
	}
plang_go_end: // I really just wanted to use a goto
	return 0;
}