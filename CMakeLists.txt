cmake_minimum_required (VERSION 3.7)

project (furnace)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set (CMAKE_CXX_STANDARD 14)
SET(CPACK_GENERATOR "TGZ")
add_subdirectory("cpp-commander/src")
add_subdirectory("furnace")

include_directories("furnace")
include(CPack)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost COMPONENTS unit_test_framework system filesystem)
enable_testing()
include_directories (${Boost_INCLUDE_DIRS})
file(GLOB TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} tests/*.cpp)
# Gather all the tests and put the executables into a testBin folder
foreach(testSrc ${TEST_SRCS})
        # Gather test files
        get_filename_component(testName ${testSrc} NAME_WE)
        # Add them as executable content
        add_executable(${testName} ${testSrc})
        # Link them as libraries.
        target_link_libraries(${testName} ${Boost_LIBRARIES})
        set_target_properties(${testName} PROPERTIES
                              RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/testBin)
        # Add them as tests into a testBin directory
        add_test(NAME ${testName}
                 WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build/testBin
                 COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/build/testBin/${testName} )
endforeach(testSrc)
