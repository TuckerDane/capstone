#include "catch.hpp"
#include "Trap.hpp"
#include "Item.hpp"
#include "Object.hpp"
#include "Colors.hpp"

TEST_CASE("default constructor sets Trap Class variables", "[Trap][Constructor]")
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