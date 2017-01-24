#include <iostream>
#include <string>
#include <Commander/ArgumentRegistry.hpp>
#include <Commander/CommandDescriptor.hpp>
#include "CreateCommand.hpp"
//#include <aws/cloudformation/CloudFormationClient.h>
#include <aws/cloudformation/CloudFormationClient.h>

namespace Commands {
  void CreateCommand::Execute(Commander::ArgumentRegistry* args)
  {
    std::cout << "Create Command is executed..." << std::endl;

    if (args->FindByKey("verbose") != nullptr) {
      std::cout << "Verbose mode is active..." << std::endl;
    }
    Aws::CloudFormation::CloudFormationClient cfClient;
  }

  Commander::CommandDescriptor* NewCreateCommand(const std::string appName)
  {
    Commander::CommandDescriptor* desc;

    desc = new Commander::CommandDescriptor("create", new CreateCommand());

    return desc;
  }
}
