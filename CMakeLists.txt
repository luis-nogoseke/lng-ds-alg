cmake_minimum_required(VERSION 3.9)
project("lfn-data-structure")

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra -Wpedantic -Wconversion \
-Wcast-align -Wunused -Wshadow -Wold-style-cast -Wpointer-arith -Wcast-qual -Wno-missing-braces")


option(CODE_COVERAGE "Enable coverage reporting" OFF)
if(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  message("Building with coverage")
  # Add required flags (GCC & LLVM/Clang)
  SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -fprofile-instr-generate -fcoverage-mapping -g -O0")
endif(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "Clang")

# Coverage with clang++
# tests/unitTests
# llvm-profdata-8 merge -sparse default.profraw -o tests.profdata
# llvm-cov-8 report ./tests/ tests/unitTests     -instr-profile=foo.profdata

# run-clang-tidy -checks='-*,bugprone-*,performance-*,modernize-*,-modernize-use-noexcept'

#####################################################
set(SOURCE_FILES src/main.cc)
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})

include_directories(src)
include_directories(include)
#####################################################

# Build tests
add_subdirectory(tests)
#####################################################

# Doxygen Build
option(BUILD_DOC "Build Documentation" ON)

find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR ${CMAKE_SOURCE_DIR}/docs)
    if(NOT EXISTS ${BUILD_DOC_DIR})
        file(MAKE_DIRECTORY ${BUILD_DOC_DIR})
    endif()

    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)
#####################################################
