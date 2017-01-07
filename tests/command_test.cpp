#define BOOST_TEST_MODULE commands
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "../cpp-commander/src/CommandRegistry.hpp"
#include "../furnace/commands/CreateCommand.hpp"

BOOST_AUTO_TEST_CASE( registry )
{
    BOOST_TEST_MESSAGE("Running none testing test for now.");
    int i = 2;
    const char *a[] = {
        (char*)("furnace"),
        (char*)("create")
    };
    Commander::CommandRegistry* registry = new Commander::CommandRegistry(i, a);
    registry->Register(&(Commands::NewCreateCommand));
    // If this would be a nullptr, the test would fail.
    BOOST_CHECK(registry);
}
