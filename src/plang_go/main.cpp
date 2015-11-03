#include <plang/plang.h>
#include <plang/TokenStream.h>

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
		plang::TokenStream tokstr(buf);
		const char* tok;
		while ((tok = tokstr.getNext()) != 0) {
			if (tok[0] == ':') {
				if ((tok = tokstr.getNext()) != 0) {
					if (tok[0] == 'q') {
						goto plang_go_end;
					}
				}	
			} else {
				std::cout << tok << "_";
			}
		}
		std::cout << std::endl;
	}
plang_go_end: // I really just wanted to use a goto
	return 0;
}