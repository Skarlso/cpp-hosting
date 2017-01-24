aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/commands COMMANDS_SOURCES)

# General -l switch addition for the linker so every object / executable / tests are getting the here included header files.
link_libraries(aws-cpp-sdk-core)
link_libraries(aws-cpp-sdk-cloudformation)
link_libraries(commander)
# Create a library which we can re-use later for the testing executable as well.
add_library(furnace_object OBJECT ${COMMANDS_SOURCES})

# Use the created library to link to the source.
add_executable(furnace furnace.cpp ${COMMANDS_SOURCES})

install(TARGETS furnace RUNTIME DESTINATION "${CMAKE_BINARY_DIR}/bin")
