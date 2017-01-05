#ifndef COMMAND_H
#define COMMAND_H
#include <string>
#include <vector>

class Command
{
    public:
        virtual void execute(std::vector<std::string>) = 0;
        virtual void help() = 0;
};

#endif
