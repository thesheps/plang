#include <plang/plang.h>

#include <iostream>

////////////////////////////////////////////////////////////////////////////////
int main(int argc, char** argv)
{
	while(1 == 1)
	{
		string input;
  		std::cout << "> ";
  		getline (std::cin, input);

  		if (input == "exit")
  		{
  			return 0;
  		}

  		std::cout << plang::Parse(input) << "\n";
	}
}