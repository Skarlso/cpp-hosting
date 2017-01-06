#include "../cpp-commander/src/CommandRegistry.hpp"

#include "commands/CreateCommand.hpp"

int main(int argc, const char *argv[])
{

  Commander::CommandRegistry* registry = new Commander::CommandRegistry(argc, argv);

  registry->Register(&(Commands::NewCreateCommand));

  registry->Dump();

  registry->Execute();

  return 0;
}
