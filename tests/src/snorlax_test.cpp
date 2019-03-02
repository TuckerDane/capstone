#include "catch.hpp"
#include "Snorlax.hpp"
#include "Colors.hpp"

TEST_CASE("default constructor sets Snorlax Class variables", "[snorlax][constructor]")
{
    Snorlax m;
    REQUIRE( m.getName() == "Snorlax" );
    REQUIRE( m.getType() == "snorlax");
    REQUIRE( m.getSymbol() == "Ω");
    REQUIRE( m.getColor() == COLOR_WHITE);
    REQUIRE( m.getDescription() == "A sleeping POKéMON blocks the way!");
}

TEST_CASE("overload constructor 1 sets Snorlax Class variables", "[snorlax][constructor]")
{
    Snorlax m(5, 15);
    REQUIRE( m.getYPos() == 5);
    REQUIRE( m.getXPos() == 15);
    REQUIRE( m.getName() == "Snorlax" );
    REQUIRE( m.getType() == "snorlax");
    REQUIRE( m.getSymbol() == "Ω");
    REQUIRE( m.getColor() == COLOR_WHITE);
    REQUIRE( m.getDescription() == "A sleeping POKéMON blocks the way!");
}

TEST_CASE("set snorlax type", "[snorlax][set]")
{
    Snorlax m;
    REQUIRE( m.getType() == "snorlax");
    m.setType("");
    REQUIRE( m.getType() == "");
    m.setType("mMoOvVaABblE");
    REQUIRE( m.getType() == "mMoOvVaABblE");
}

TEST_CASE("set Snorlax name", "[snorlax][set]")
{
    Snorlax m;
    REQUIRE ( m.getName() == "Snorlax");
    m.setName("pikachu");
    REQUIRE ( m.getName() == "pikachu");
}

TEST_CASE("set snorlax description", "[snorlax][get][set]")
{
    Snorlax m;
    REQUIRE (m.getDescription() == "A sleeping POKéMON blocks the way!");
    m.setDescription("What's a POKéMON?");
    REQUIRE (m.getDescription() == "What's a POKéMON?");
    m.setDescription("");
    REQUIRE (m.getDescription() == "");
}