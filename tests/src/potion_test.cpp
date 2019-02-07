#include "catch.hpp"
#include "Potion.hpp"
#include "Colors.hpp"

TEST_CASE("default constructor sets Potion Class variables", "[potion][constructor]")
{
    Potion p;
    REQUIRE( p.getName() == "generic potion" );
    REQUIRE( p.getType() == "potion");
    REQUIRE( p.getWeight() == 2);
    REQUIRE( p.getHealing() == 4);
    REQUIRE( p.getSymbol() == 'P');
    REQUIRE( p.getColor() == COLOR_GREEN);
    REQUIRE( p.getDescription() == "Heals the player for 4 HP");
}

TEST_CASE("overload constructor sets potion Class variables", "[potion][constructor]")
{
    Potion p(12, 2);
    REQUIRE( p.getYPos() == 12);
    REQUIRE( p.getXPos() == 2);
    REQUIRE( p.getName() == "health potion" );
    REQUIRE( p.getType() == "potion");
    REQUIRE( p.getWeight() == 2);
    REQUIRE( p.getHealing() == 4);
    REQUIRE( p.getSymbol() == 'P');
    REQUIRE( p.getColor() == COLOR_GREEN);
    REQUIRE( p.getDescription() == "Heals the player for 4 HP");
}

TEST_CASE("set potion type", "[potion][set]")
{
    Potion p;
    REQUIRE( p.getType() == "potion");
    p.setType("");
    REQUIRE( p.getType() == "");
    p.setType("THEpotionOFTRUTH");
    REQUIRE( p.getType() == "THEpotionOFTRUTH");
}

TEST_CASE("set potion name", "[potion][set]")
{
    Potion p;
    REQUIRE ( p.getName() == "generic potion");
    p.setName("green potion");
    REQUIRE ( p.getName() == "green potion");
}

TEST_CASE("set potion weight", "[potion][get][set]")
{
    Potion p;
    REQUIRE (p.getWeight() == 2 );
    p.setWeight(20);
    REQUIRE (p.getWeight() == 20);
    p.setWeight(0);
    REQUIRE (p.getWeight() == 0);
    p.setWeight(-49);
    REQUIRE (p.getWeight() == -49);
}

TEST_CASE("set potion description", "[potion][get][set]")
{
    Potion p;
    REQUIRE (p.getDescription() == "Heals the player for 4 HP");
    p.setDescription("does nothing at all");
    REQUIRE (p.getDescription() == "does nothing at all");
    p.setDescription("");
    REQUIRE (p.getDescription() == "");
}

TEST_CASE("get and set potion healing", "[potion][get][set]")
{
    Potion p;
    REQUIRE (p.getHealing() == 4);
    p.setHealing(6);
    REQUIRE (p.getHealing() == 6);
    p.setHealing(0);
    REQUIRE (p.getHealing() == 0);
}