#ifndef plang_TokenStream_h
#define plang_TokenStream_h

#include "token.h"

namespace plang {

////////////////////////////////////////////////////////////////////////////////
/// \class TokenStream
/// Returns tokens sequentially from a char stream.
////////////////////////////////////////////////////////////////////////////////
class TokenStream
{
public:
	/// Init from an existing char buffer.
	/// \note The buffer is modified by calls to \c getNext().
	TokenStream(char* _buf_);

	/// \return The next token in the stream (a null-terminated string). 
	Token getNext();

private:	
	char* m_buf;
	const char* m_optoken;

}; // class TokenStream

} // namespace plang

#endif // plang_TokenStream_h