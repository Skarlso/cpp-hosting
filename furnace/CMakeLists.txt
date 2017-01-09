aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/commands COMMANDS_SOURCES)

# Create a library which we can re-use later for the testing executable as well.
add_library(furnace_object OBJECT ${COMMANDS_SOURCES})

# Find the installed AWS core package
# Don't need all of them
find_package(aws-sdk-cpp)

# Use the created library to link to the source.
add_executable(furnace $<TARGET_OBJECTS:furnace_object> furnace.cpp)

# # Adding any dylib from lib folder if present.
# if (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
#     file(GLOB LIBRARIES "../lib/*.so")
# elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
#     file(GLOB LIBRARIES "../lib/*.dylib")
# endif()
#
# message("LIBRARIES = ${LIBRARIES}")

target_link_libraries(furnace aws-sdk-cpp-core)

target_link_libraries(furnace commander)

install(TARGETS furnace RUNTIME DESTINATION "${CMAKE_BINARY_DIR}/bin")
