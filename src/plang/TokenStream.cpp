#include <plang/TokenStream.h>

#include <plang/def.h>

using namespace plang;

static const char* kOpTokenStrings = "=+-/*:(){}";

static bool isWhiteSpace(char _c)
{
	//static const char* kWhitespace = " \t\n";
	//for (const char* it = kWhitespace; *it != 0; ++it) {
	//	if (_c == *it) {
	//		return true;
	//	}
	//}
	//return false;
	return _c <= ' ';
}

static const char* getOpTokenString(char _c)
{
	for (const char* it = kOpTokenStrings; *it != '\0'; ++it) {
		if (_c == *it) {
			return it;
		}
	}
	return 0;
}

TokenStream::TokenStream(char* _buf_) : m_buf(_buf_) , m_optoken(0)
{
	PLANG_ASSERT(_buf_);
	//	advance to first token
	while (*m_buf && isWhiteSpace(*m_buf)) {
		++m_buf;
	}
}

Token TokenStream::getNext()
{
	// if m_optoken was set, interrupt the stream and return an op token string (we 
	// can't guarantee to insert a null char after an op token)
	if (m_optoken) {
		const char* ret = m_optoken;
		m_optoken = 0;
		return ret;
	}

	// detect end of stream
	if (!m_buf) {
		return Token::Eos; 
	}

	// advance to next non-whitespace char (start of the next token)
	while (*m_buf && isWhiteSpace(*m_buf)) {
		++m_buf;
	}
	const char* ret = m_buf;

	// advance to next whitespace char, op token or eos
	while (*m_buf && !isWhiteSpace(*m_buf)) {
		m_optoken = getOpTokenString(*m_buf);
		if (m_optoken) {
			break; // break here, optoken in m_buf is replaced with 0
		}
		++m_buf;
	}
	if (*m_buf) {
	// replace whitespace with 0
		*m_buf = 0;
		++m_buf;
	} else {
	// signal eos
		m_buf = 0;
	}

	// special case; ret can be null if we have an op token first in the stream 
	// (or if the stream contains consecutive op tokens), in which case we can
	// consume m_optoken here
	if (*ret == 0) {
		ret = m_optoken;
		m_optoken = 0;
	}

	// another special case, if there was whitespace at the end of the stream then
	// ret can be null
	if (ret == 0) {
		return Token::Eos;
	}

	return Token(ret);
}