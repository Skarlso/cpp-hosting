#include <iostream>
#include <string>
#include "CreateCommand.hpp"
#include "../../cpp-commander/src/ArgumentRegistry.hpp"
#include "../../cpp-commander/src/CommandDescriptor.hpp"

namespace Commands {
  void CreateCommand::Execute(Commander::ArgumentRegistry* args)
  {
    std::cout << "Create Command is executed..." << std::endl;

    if (args->FindByKey("verbose") != nullptr) {
      std::cout << "Verbose mode is active..." << std::endl;
    }
  }

  Commander::CommandDescriptor* NewCreateCommand(const std::string appName)
  {
    Commander::CommandDescriptor* desc;

    desc = new Commander::CommandDescriptor("create", new CreateCommand());

    return desc;
  }
}
