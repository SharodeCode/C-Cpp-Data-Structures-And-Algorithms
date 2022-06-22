cmake_minimum_required(VERSION 3.10)

set(THIS ${PROJECT_NAME}-test)

set(SOURCE_FILES
    ../DataStructures/source/Test.cpp
    queue-test.cpp
)

add_subdirectory(googletest)

include_directories(../DataStructures/include)

add_executable(${THIS} ${SOURCE_FILES})

# Set a fake version to test
target_compile_definitions(${THIS} PRIVATE
    DATASTRUCTURESANDALGORITHMS_MAJOR_VERSION=1
    DATASTRUCTURESANDALGORITHMS_MINOR_VERSION=2
)

target_link_libraries(${THIS} gtest_main)

add_test(NAME ${THIS} COMMAND ${THIS})

