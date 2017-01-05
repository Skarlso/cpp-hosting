#include "actions.h"
#include "create_command.h"
#include "command.h"
#include <map>
#include <string>
#include <iostream>
#include <stdio.h>
// C++ Noob Note: Because * comes after the type. This is a pointer type value
// And not * Command. Command is the type.
std::map<std::string, Command *> commands;


void printAvailableActions() {
    std::cerr << "Please use one of the following available actions: " << '\n';
    for (auto it = commands.begin(); it != commands.end(); ++it) {
        printf("Action: %s\n", it->first.c_str());
    }
}

int main(int argc, char* args[]) {
    Actions *action = new Actions;
    CreateCommand *cc = new CreateCommand(action);
    commands["create"] = cc;
    if (argc <= 1) {
        printAvailableActions();
        return 1;
    }
    std::string current = args[1];
    if (commands.find(current) == commands.end()) {
        printAvailableActions();
        return 1;
    }
    std::vector<std::string> allArgs(args, args + argc);
    commands[current]->execute(allArgs);
    return 0;
}
