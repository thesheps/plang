cmake_minimum_required(VERSION 2.8.7)
project("plang")

set(PLANG_SRC_ROOT "src")
set(PLANG_EXTERN_ROOT "extern")
set(GCC_COMPILE_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}" )

include_directories(${PLANG_SRC_ROOT})
link_directories   (${LIBRARY_OUTPUT_PATH})

# plang
file(GLOB PLANG_SRC ${PLANG_SRC_ROOT}/plang/*.cpp)
add_library(plang STATIC ${PLANG_SRC})

# plang_go
file(GLOB PLANG_GO_SRC ${PLANG_SRC_ROOT}/plang_go/*.cpp)
add_executable(plang_go ${PLANG_GO_SRC})
target_link_libraries(plang_go plang)

# plang_unit
file(GLOB PLANG_UNIT_SRC ${PLANG_SRC_ROOT}/plang_unit/*.cpp)
add_executable(plang_unit ${PLANG_UNIT_SRC})
target_link_libraries(plang_unit plang)

include(ExternalProject)

# gtest
ExternalProject_Add(
	"gtest"
	# download
		GIT_REPOSITORY https://github.com/google/googletest.git
		#SVN_REPOSITORY http://googletest.googlecode.com/svn/trunk
	# update/patch
		#UPDATE_COMMAND ""
	
	# configure
		CONFIGURE_COMMAND cmake -G ${CMAKE_GENERATOR} "${CMAKE_CURRENT_BINARY_DIR}/gtest-prefix/src/gtest/googletest/"
		CMAKE_ARGS -DBUILD_SHARED_LIBS=OFF
				-Dgtest_force_shared_crt=OFF
				-Dgtest_build_tests=OFF
				-Dgtest_build_samples=OFF
				-Dgtest_disable_pthreads=ON
	# build
		#BUILD_COMMAND ""
	# install
		INSTALL_COMMAND ""
)
