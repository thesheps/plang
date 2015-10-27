#include "plang.h"

#include <iostream>

using namespace plang;

////////////////////////////////////////////////////////////////////////////////
void plang::HelloWorld()
{
#ifdef PLANG_DEBUG
	std::cout << "PLANG_DEBUG" << std::endl;
#endif
	std::cout << "plang says hello, world!" << std::endl;
}