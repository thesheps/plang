<<<<<<< HEAD
=======
#include <plang/plang.h>

>>>>>>> 8dc874e9e7889c901f29e0eebd679e0aeb521ce2
#include <iostream>

#include <plang/parser.h>

using namespace plang;

int main(int argc, char** argv)
{
  Parser parser = Parser();

<<<<<<< HEAD
  while(1 == 1)
  {
    std::string input;
    std::cout << "> ";
    getline (std::cin, input);
=======
	while (true) {
		std::string input;
  		std::cout << "> ";
  		getline(std::cin, input);
>>>>>>> 8dc874e9e7889c901f29e0eebd679e0aeb521ce2

    if (input == "exit")
    {
      return 0;
    }

    std::cout << parser.parse(input) << "\n";
  }
}