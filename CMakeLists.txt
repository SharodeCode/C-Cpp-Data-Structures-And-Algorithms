cmake_minimum_required(VERSION 3.10)

project(C-CPP-DATA-STRUCTURES-AND-ALGORITHMS)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  Test
  test/QueueTests.cc
)

target_link_libraries(
  Test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(Test)

