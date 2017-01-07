#ifndef _CreateCommand_hpp_
#define _CreateCommand_hpp_

#include <string>
#include "../../cpp-commander/src/Command.hpp"
#include "../../cpp-commander/src/CommandDescriptor.hpp"
#include "../../cpp-commander/src/ArgumentRegistry.hpp"


namespace Commands {
  class CreateCommand : public Commander::Command {
    void Execute(Commander::ArgumentRegistry* args);
  };

  Commander::CommandDescriptor* NewCreateCommand(const std::string appName);
}

#endif
