aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/commands COMMANDS_SOURCES)

# Create a library which we can re-use later for the testing executable as well.
add_library(furnace_object OBJECT ${COMMANDS_SOURCES})

# Find the installed AWS core package
# Don't need all of them
set(aws-sdk-cpp_DIR $ENV{AWS_SDK_CPP_DIR})
find_package(aws-sdk-cpp)

# Use the created library to link to the source.
add_executable(furnace $<TARGET_OBJECTS:furnace_object> furnace.cpp)

target_link_libraries(furnace aws-cpp-sdk-core)

target_link_libraries(furnace commander)
install(TARGETS furnace RUNTIME DESTINATION "${CMAKE_BINARY_DIR}/bin")
