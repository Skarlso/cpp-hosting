#include "create_command.h"
#include <iostream>

void CreateCommand::execute() {
    mAction->create();
}

void CreateCommand::help() {
    std::cout << "Display help message for Create" << '\n';
}
