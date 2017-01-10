#ifndef _CreateCommand_hpp_
#define _CreateCommand_hpp_

#include <string>
#include <Commander/Command.hpp>
#include <Commander/CommandDescriptor.hpp>
#include <Commander/ArgumentRegistry.hpp>


namespace Commands {
  class CreateCommand : public Commander::Command {
    void Execute(Commander::ArgumentRegistry* args);
  };

  Commander::CommandDescriptor* NewCreateCommand(const std::string appName);
}

#endif
