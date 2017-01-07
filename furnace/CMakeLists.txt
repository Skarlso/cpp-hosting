aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/commands COMMANDS_SOURCES)

add_executable(furnace furnace.cpp ${COMMANDS_SOURCES})

target_link_libraries(furnace commander)

install(TARGETS furnace RUNTIME DESTINATION "${CMAKE_BINARY_DIR}/bin")
