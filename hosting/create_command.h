#ifndef CREATE_COMMAND_H
#define CREATE_COMMAND_H
#include "command.h"
#include "actions.h"

class CreateCommand : public Command
{
    public:
        CreateCommand(Actions *action) : mAction(action) {};
        void execute();
        void help();
    private:
        Actions *mAction;
};
#endif
