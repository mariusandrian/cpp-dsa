cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_COMPILER /opt/homebrew/bin/g++-15)

# IMPT: put project AFTER setting compiler. Else, it will infinitely loop.
project(CppDsa)

# Default to Debug (-g)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

include(FetchContent)

# FetchContent_Declare(
#   Catch2
#   GIT_REPOSITORY https://github.com/catchorg/Catch2.git
#   GIT_TAG        v3.8.1 # or a later release
# )
# FetchContent_MakeAvailable(Catch2)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

# Prevent overriding parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googletest)

# add_executable(tests test.cpp)

enable_testing()

add_executable(array_t_test array/array_t_test.cpp)
target_link_libraries(
  array_t_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(array_t_test)

# target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)


