include(FetchContent)

option(BUILD_GMOCK OFF)
option(INSTALL_GTEST OFF)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.0
)

FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(main main.cpp SimpleMMTests.cpp QueueTests.cpp StackTests.cpp)

target_link_libraries(main
 PRIVATE
  GTest::GTest
  SimpleMM)

add_test(multiply_gtests multiply_test)
add_test(SimpleMM_gtests SimpleMMTests)
add_test(Queue_gtests QueueTests)