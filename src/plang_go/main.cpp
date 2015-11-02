#include <iostream>

#include <plang/parser.h>

using namespace plang;

int main(int argc, char** argv)
{
  Parser parser = Parser();

  while(1 == 1)
  {
    std::string input;
    std::cout << "> ";
    getline (std::cin, input);

    if (input == "exit")
    {
      return 0;
    }

    std::cout << parser.parse(input) << "\n";
  }
}