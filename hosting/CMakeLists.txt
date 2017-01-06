aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/commands COMMANDS_SOURCES)

add_executable(hosting hosting.cpp ${COMMANDS_SOURCES})

target_link_libraries(hosting commander)

install(TARGETS hosting RUNTIME DESTINATION "${CMAKE_BINARY_DIR}/bin")
