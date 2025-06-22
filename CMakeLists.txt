cmake_minimum_required(VERSION 3.10)

project(typesystem_aoc VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -pedantic -ftemplate-depth=2000000000 -pipe -O0")

include_directories(txx)
add_executable(main main.cc)

