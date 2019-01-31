#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Key.hpp"
#include "Item.hpp"
#include "Object.hpp"
#include "../../src/game_objects/Key.cpp"
#include "../../src/game_objects/Item.cpp"
#include "../../src/game_objects/Object.cpp"
#include "../../src/game_objects/Door.cpp"

TEST_CASE("Default Constructor", "[Key]")
{
    Key k;
    REQUIRE( k.getType() == "key" );
    REQUIRE( k.getName() == "normal key");
    REQUIRE( k.getPassword() == -1);
    REQUIRE( k.getWeight() == 1);
    REQUIRE( k.getDescription() == "used to unlock doors");
}

TEST_CASE("Overload Constructor", "[Key]")
{
    Key k("keyname", 1);
     REQUIRE( k.getType() == "key" );
    REQUIRE( k.getName() == "keyname");
    REQUIRE( k.getPassword() == 1);
    REQUIRE( k.getWeight() == 1);
    REQUIRE( k.getDescription() == "used to unlock doors");   
}