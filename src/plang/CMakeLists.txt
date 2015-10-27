cmake_minimum_required(VERSION 2.8)

# Sources
file(GLOB plang_SOURCES *.cpp)
file(GLOB plang_HEADER *.h)

# Executable
add_library(plang ${plang_SOURCES} ${plang_HEADERS})