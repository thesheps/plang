#ifndef parser_h
#define parser_h

#if   defined(__GNUC__)
	#define PLANG_COMPILER_GNU
#elif defined(_MSC_VER)
	#define PLANG_COMPILER_MSVC
#endif

#include <string>

using std::string;

namespace plang {
	class Parser {
		public:
			Parser();
			std::string parse(string input);	
	};
}

#endif // parser_h