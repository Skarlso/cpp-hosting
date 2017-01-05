#ifndef CREATE_COMMAND_H
#define CREATE_COMMAND_H
#include "command.h"
#include "actions.h"
#include <string>
#include <vector>

class CreateCommand : public Command
{
    public:
        CreateCommand(Actions *action) : mAction(action) {};
        void execute(std::vector<std::string>);
        void help();
    private:
        Actions *mAction;
};
#endif
