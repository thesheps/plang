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

# catch
include(ExternalProject)
ExternalProject_Add(
    catch
    PREFIX ${CMAKE_BINARY_DIR}/catch
    GIT_REPOSITORY https://github.com/philsquared/Catch.git
    TIMEOUT 10
    UPDATE_COMMAND ${GIT_EXECUTABLE} pull
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
)

# Expose required variable (CATCH_INCLUDE_DIR) to parent scope
ExternalProject_Get_Property(catch source_dir)
set(CATCH_INCLUDE_DIR ${source_dir}/include CACHE INTERNAL "Path to include folder for Catch")

# Includes Catch in the project:
add_subdirectory(${EXT_PROJECTS_DIR}/catch)
include_directories(${CATCH_INCLUDE_DIR} ${COMMON_INCLUDES})
enable_testing(true)
