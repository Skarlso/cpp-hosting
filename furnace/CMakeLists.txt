aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/commands COMMANDS_SOURCES)

# Create a library which we can re-use later for the testing executable as well.
add_library(furnace_object OBJECT ${COMMANDS_SOURCES})

# Adding AWS SDK.
# set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /usr/local/lib)
find_library(aws-sdk-cpp
             NAMES aws-sdk-cpp
)

# Use the created library to link to the source.
add_executable(furnace $<TARGET_OBJECTS:furnace_object> furnace.cpp)

target_link_libraries(furnace commander)

# Adding any dylib from lib folder if present.
file(GLOB LIBRARIES "../lib/*.dylib")
message("LIBRARIES = ${LIBRARIES}")
target_link_libraries(furnace ${LIBRARIES})

# Adding specific AWS dependencies
target_link_libraries(furnace aws-cpp-sdk-core)

install(TARGETS furnace RUNTIME DESTINATION "${CMAKE_BINARY_DIR}/bin")
