cmake_minimum_required (VERSION 2.8.8)

project (furnace)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set (CMAKE_CXX_STANDARD 14)
set (CPACK_GENERATOR "TGZ")

find_package(Boost COMPONENTS unit_test_framework system filesystem)
enable_testing()

# libraries to use
add_subdirectory("cpp-commander/Commander")
include_directories("cpp-commander")

# AWS SDK
if (DEFINED ENV{AWS_SDK_PATH})
    set(AWS_SDK_PATH "$ENV{AWS_SDK_PATH}/build")
else()
    set(AWS_SDK_PATH "${CMAKE_CURRENT_LIST_DIR}/aws-sdk-cpp/build")
endif()

set(aws-sdk-cpp_DIR ${AWS_SDK_PATH})
find_package(aws-sdk-cpp)

# Furnace
add_subdirectory("furnace")
add_subdirectory("tests")
include_directories("furnace")
include(CPack)
