#include "catch.hpp"
#include "Trap.hpp"
#include "Item.hpp"
#include "Object.hpp"
#include "Colors.hpp"

TEST_CASE("default constructor sets Trap Class variables", "[trap][constructor]")
{
    Trap t;
    REQUIRE( t.getName() == "Trap" );
    REQUIRE( t.getType() == "trap_item");
    REQUIRE( t.getWeight() == 2);
    REQUIRE( t.getDamage() == 6);
    REQUIRE( t.getSymbol() == 'T');
    REQUIRE( t.getColor() == COLOR_RED);
    REQUIRE( t.getDescription() == "Damages the player for 6 HP");
}

TEST_CASE("overload constructor sets Trap Class variables", "[trap][constructor]")
{
    Trap t(7, 5);
    REQUIRE( t.getYPos() == 7);
    REQUIRE( t.getXPos() == 5);
    REQUIRE( t.getName() == "Trap" );
    REQUIRE( t.getType() == "trap_item");
    REQUIRE( t.getWeight() == 2);
    REQUIRE( t.getDamage() == 6);
    REQUIRE( t.getSymbol() == 'T');
    REQUIRE( t.getColor() == COLOR_RED);
    REQUIRE( t.getDescription() == "Damages the player for 6 HP");
}