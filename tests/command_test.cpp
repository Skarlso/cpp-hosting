#define BOOST_AUTO_TEST_MAIN
#include <boost/test/auto_unit_test.hpp>
#include "../cpp-commander/src/CommandRegistry.hpp"
#include "../furnace/commands/CreateCommand.hpp"

BOOST_AUTO_TEST_CASE( registry )
{
    const int argc = 1;
    const char* argv[] = {
        (char*)("furnace"),
        (char*)("create")
    };
    Commander::CommandRegistry* registry = new Commander::CommandRegistry(argc, argv);
    // registry->Register(&(Commands::NewCreateCommand));
    // registry->Dump();
    // BOOST_CHECK_EQUAL(, 1);
}
