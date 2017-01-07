# indicates the location of the boost installation tree.
# hard-coded for our simple example.
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
include_directories(${Boost_INCLUDE_DIRS})
# Gather all the tests from test folder
# This does not include subfolders
file(GLOB TEST_SRCS *.cpp)

# For each found test, create a test executable
# TODO: Look for a way to gather executables per test suite
foreach(testSrc ${TEST_SRCS})
    # Get the filename without extension
    get_filename_component(testName ${testSrc} NAME_WE)
    # This will create an executable with the test's filename per every test file.
    # Hence all tests will have an individual test executable.
    # Use the created object under the furnace project so the this executable
    # has access to the project source.
    add_executable(${testName} $<TARGET_OBJECTS:furnace_object> ${testSrc})
    target_link_libraries(${testName} ${Boost_LIBRARIES} commander)
    # Setting the target directory to build/testBin so the executable will be located there.
    set_target_properties(${testName} PROPERTIES
                          RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../build/testBin)
    # Adding the test to run for the location which will be under ../build/testBin/$testName.
    add_test(NAME ${testName}
             WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../build/testBin
             COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/../build/testBin/${testName} )
endforeach(testSrc)
