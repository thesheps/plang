cmake_minimum_required(VERSION 2.8.8)
project("plang")

include_directories("gtest")
include_directories("src")
link_directories   ("bin")

set(GCC_COMPILE_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}" )

# plang
file(GLOB PLANG_SRC "src/plang/*.cpp")
add_library(plang STATIC ${PLANG_SRC})

# plang_go
file(GLOB PLANG_GO_SRC "src/plang_go/*.cpp")
add_executable(plang_go ${PLANG_GO_SRC})
target_link_libraries(plang_go plang)

# plang_unit
file(GLOB PLANG_UNIT_SRC "src/plang_unit/*.cpp")
add_executable(plang_unit ${PLANG_UNIT_SRC})
target_link_libraries(plang_unit plang)
