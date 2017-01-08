cmake_minimum_required (VERSION 2.8)

project (furnace)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set (CMAKE_CXX_STANDARD 14)
set (CPACK_GENERATOR "TGZ")

find_package(Boost COMPONENTS unit_test_framework system filesystem)
enable_testing()
include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory("cpp-commander/src")
add_subdirectory("furnace")
add_subdirectory("tests")
include_directories("furnace")
include(CPack)
