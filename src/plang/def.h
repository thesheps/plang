#ifndef plang_def_h
#define plang_def_h

#if   defined(__GNUC__)
	#define PLANG_COMPILER_GNU
#elif defined(_MSC_VER)
	#define PLANG_COMPILER_MSVC
#endif

#include <cstddef> // size_t
#include <cstdint> // sized ints

namespace plang {
	typedef int8_t          sint8;
	typedef uint8_t         uint8;
	typedef int16_t         sint16;
	typedef uint16_t        uint16;
	typedef int32_t         sint32;
	typedef uint32_t        uint32;
	typedef int64_t         sint64;
	typedef uint64_t        uint64;

	typedef std::ptrdiff_t  sint;
	typedef std::size_t     uint;
}

#endif // plang_def_h