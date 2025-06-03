cmake_minimum_required(VERSION 3.28.3)

project(LinkedList)

set(CMAKE_C_COMPILER clang CACHE STRING "C compiler" FORCE)
set(CMAKE_CXX_COMPILER clang++ CACHE STRING "C++ compiler" FORCE)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB HEADERS "include/*.hpp")
file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} main.cpp ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE include)

# Clang Tidy
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
target_compile_options(${PROJECT_NAME} PRIVATE)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_CLANG_TIDY "clang-tidy" # Dostosuj checks do swoich potrzeb
)