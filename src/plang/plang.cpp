#include "plang.h"

#include <iostream>

using namespace plang;

////////////////////////////////////////////////////////////////////////////////
void plang::HelloWorld()
{
#ifdef PLANG_DEBUG
	std::cout << "PLANG_DEBUG" << std::endl;
#endif
#ifdef PLANG_COMPILER_GNU
	std::cout << "PLANG_COMPILER_GNU" << std::endl;
#endif
#ifdef PLANG_COMPILER_MSVC
	std::cout << "PLANG_COMPILER_MSVC" << std::endl;
#endif
	std::cout << "Hello, world!" << std::endl;
}