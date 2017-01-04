#include <iostream>
#include "actions.h"
#include "create_command.h"

int main(int argv, char* args[]) {
    Actions *action = new Actions;

    CreateCommand *cc = new CreateCommand(action);
    cc->execute();
}
