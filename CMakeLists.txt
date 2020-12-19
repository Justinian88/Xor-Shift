cmake_minimum_required(VERSION 3.17)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled main.c wiki.h wiki.c xor.h const.h)

include_directories(/Users/justinian/Downloads/libtommath-1.2.0)
find_library(LIBTOMMATH libtommath.a /Users/justinian/Downloads/libtommath-1.2.0)

target_link_libraries(${PROJECT_NAME} PUBLIC ${LIBTOMMATH})
