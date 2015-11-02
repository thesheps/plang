#ifndef parser_h
#define parser_h

#include <string>

namespace plang {
	class Parser {
		public:
			Parser();
			std::string parse(std::string input);	
	};
}

#endif // parser_h