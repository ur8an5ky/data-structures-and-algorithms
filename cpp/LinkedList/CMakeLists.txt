cmake_minimum_required(VERSION 3.28.3)

project(LinkedList)

set(CMAKE_C_COMPILER clang CACHE STRING "C compiler" FORCE)
set(CMAKE_CXX_COMPILER clang++ CACHE STRING "C++ compiler" FORCE)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

# coverage flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-instr-generate -fcoverage-mapping")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-instr-generate -fcoverage-mapping")

file(GLOB HEADERS "include/*.hpp")
file(GLOB SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} main.cpp ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE include)

find_package(GTest REQUIRED)

# UT
add_executable(LinkedListTests tests/test_linked_list.cpp ${SOURCES})
target_include_directories(LinkedListTests PRIVATE include)
target_link_libraries(LinkedListTests PRIVATE GTest::GTest GTest::Main Threads::Threads)

include(GoogleTest)
gtest_discover_tests(LinkedListTests)

# coverage
add_custom_target(coverage
    COMMAND ${CMAKE_COMMAND} -E env LLVM_PROFILE_FILE=default.profraw $<TARGET_FILE:LinkedListTests>
    COMMAND llvm-profdata merge -sparse default.profraw -o default.profdata
    COMMAND llvm-cov report $<TARGET_FILE:LinkedListTests> -instr-profile=default.profdata
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    DEPENDS LinkedListTests
    COMMENT "Running coverage analysis"
)

add_custom_target(coverage_html
    COMMAND ${CMAKE_COMMAND} -E env LLVM_PROFILE_FILE=default.profraw $<TARGET_FILE:LinkedListTests>
    COMMAND llvm-profdata merge -sparse default.profraw -o default.profdata
    COMMAND llvm-cov show $<TARGET_FILE:LinkedListTests> -instr-profile=default.profdata -format=html -output-dir=${CMAKE_BINARY_DIR}/coverage_report
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    DEPENDS LinkedListTests
    COMMENT "Generating coverage HTML report"
)