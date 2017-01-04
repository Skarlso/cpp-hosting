#include <iostream>
#include "actions.h"
#include "create_command.h"
#include "command.h"
#include <map>
#include <string>

// C++ Noob Note: Because * comes after the type. This is a pointer type value
// And not * Command. Command is the type.
std::map<std::string, Command *> commands;

int main(int argv, char* args[]) {
    Actions *action = new Actions;

    CreateCommand *cc = new CreateCommand(action);
    commands["create"] = cc;
    return 0;
}
