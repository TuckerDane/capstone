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

TEST_CASE("set trap type", "[trap][set]")
{
    Trap t;
    REQUIRE( t.getType() == "trap_item");
    t.setType("");
    REQUIRE( t.getType() == "");
    t.setType("THEtrapOFTRUTH");
    REQUIRE( t.getType() == "THEtrapOFTRUTH");
}

TEST_CASE("set trap name", "[trap][set]")
{
    Trap t;
    REQUIRE ( t.getName() == "Trap");
    t.setName("green trap");
    REQUIRE ( t.getName() == "green trap");
}

TEST_CASE("set trap weight", "[trap][get][set]")
{
    Trap t;
    REQUIRE (t.getWeight() == 2 );
    t.setWeight(20);
    REQUIRE (t.getWeight() == 20);
    t.setWeight(0);
    REQUIRE (t.getWeight() == 0);
    t.setWeight(-49);
    REQUIRE (t.getWeight() == -49);
}

TEST_CASE("set trap description", "[trap][get][set]")
{
    Trap t;
    REQUIRE (t.getDescription() == "Damages the player for 6 HP");
    t.setDescription("does nothing at all");
    REQUIRE (t.getDescription() == "does nothing at all");
    t.setDescription("");
    REQUIRE (t.getDescription() == "");
}