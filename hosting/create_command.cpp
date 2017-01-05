#include "create_command.h"
#include <iostream>
#include <string>
#include <vector>

void CreateCommand::execute(std::vector<std::string> args) {
    // Parsing of args happens here.
    std::cout << "Args count: " << args.size() << '\n';
    mAction->create(args);
}

void CreateCommand::help() {
    std::cout << "Display help message for Create" << '\n';
}
