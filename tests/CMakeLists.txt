project(${CMAKE_PROJECT_NAME}_tests)

# Clone Google Test
set(GOOGLETEST_DIR ${CMAKE_SOURCE_DIR}/tests/lib/googletest)
if(NOT EXISTS ${GOOGLETEST_DIR})
    find_package(Git REQUIRED)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} clone https://github.com/google/googletest ${GOOGLETEST_DIR}
    )
endif()

add_subdirectory(lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(unitTests
    stack_test.cc
    binary_search_test.cc
)

target_link_libraries(unitTests gtest gtest_main)
