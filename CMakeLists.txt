cmake_minimum_required(VERSION 3.10)

option(BUILD_DATASTRUCTURES "Build Data Structures library" ON)
option(BUILD_TESTS "Build the tests." ON)

if(BUILD_DATASTRUCTURES)
    add_subdirectory(DataStructures)
endif()

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()
