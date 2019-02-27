cmake_minimum_required(VERSION 3.9.4)
project(cpp)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
include_directories(".")

add_executable(test-dmp dmp.cc)

add_custom_target(
        format
        COMMAND clang-format
        -style='{BasedOnStyle: Google, IndentWidth: 4}'
        -i
        ${CMAKE_SOURCE_DIR}/*.cc
        ${CMAKE_SOURCE_DIR}/*.hpp
)

add_custom_target(
        fuzz
        COMMAND clang++ ${CMAKE_SOURCE_DIR}/fuzz-diff.cc -fsanitize=undefined,address,fuzzer -fno-sanitize-recover=undefined -g -O2 -o fuzz-diff 
)
