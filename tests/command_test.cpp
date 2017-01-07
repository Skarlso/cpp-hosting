// #define BOOST_TEST_MAIN
// #define BOOST_TEST_DYN_LINK
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE "commands"
#include <boost/test/unit_test.hpp>
#include "../cpp-commander/src/CommandRegistry.hpp"
#include "../furnace/commands/CreateCommand.hpp"

BOOST_AUTO_TEST_CASE( registry )
{
    int i = 2;
    const char *a[] = {
        (char*)("furnace"),
        (char*)("create")
    };
    Commander::CommandRegistry* registry = new Commander::CommandRegistry(i, a);
    BOOST_TEST_MESSAGE ("ANYAD");
    BOOST_CHECK(true);
    // registry->Register(&(Commands::NewCreateCommand));
    // registry->Dump();
    // BOOST_CHECK_EQUAL(, 1);
}
