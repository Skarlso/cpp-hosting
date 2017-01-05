#ifndef COMMAND_H
#define COMMAND_H

class Command
{
    public:
        virtual void execute() = 0;
        virtual void help() = 0;
};

#endif
