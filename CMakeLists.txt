cmake_minimum_required(VERSION 2.8.7)
project("plang")

include_directories("gtest")
include_directories("src")
link_directories   ("bin")

# sets
set(EXT_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/lib)
set(GCC_COMPILE_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}" )
set(PROJECT_NAME_STR plang)
project(${PROJECT_NAME_STR} C CXX)
find_package(Threads REQUIRED)

# external modules
add_subdirectory(${EXT_PROJECTS_DIR}/gtest)

# testing
add_definitions(${MSVC_COMPILER_DEFS})
enable_testing()
set(PROJECT_TEST_NAME ${PROJECT_NAME_STR}_test)

# plang
file(GLOB PLANG_SRC src/plang/*.cpp)
add_library(plang STATIC ${PLANG_SRC})

# plang_go
file(GLOB PLANG_GO_SRC src/plang_go/*.cpp)
add_executable(plang_go ${PLANG_GO_SRC})
target_link_libraries(plang_go plang)

# plang_unit
file(GLOB PLANG_UNIT_SRC src/plang_unit/*.cpp)
add_executable(plang_unit ${PLANG_UNIT_SRC})
add_dependencies(${PROJECT_TEST_NAME} googletest)

target_link_libraries(plang_unit plang)

add_test(test1 ${PROJECT_TEST_NAME})
