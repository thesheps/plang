<<<<<<< HEAD
#ifndef parser_h
#define parser_h
=======
#ifndef plang_parser_h
#define plang_parser_h
>>>>>>> 8dc874e9e7889c901f29e0eebd679e0aeb521ce2

#include <string>

namespace plang {
<<<<<<< HEAD
	class Parser {
		public:
			Parser();
			std::string parse(std::string input);	
	};
=======

////////////////////////////////////////////////////////////////////////////////
/// \class Parser
////////////////////////////////////////////////////////////////////////////////	
class Parser 
{
public:
	Parser();
	
	std::string parse(const std::string& _input);	
};

>>>>>>> 8dc874e9e7889c901f29e0eebd679e0aeb521ce2
}

#endif // parser_h