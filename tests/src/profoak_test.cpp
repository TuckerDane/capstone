#include "catch.hpp"
#include "Profoak.hpp"
#include "Colors.hpp"

TEST_CASE("default constructor sets Profoak Class variables", "[profoak][constructor]")
{
    Profoak m;
    REQUIRE( m.getName() == "Professor Oak" );
    REQUIRE( m.getType() == "profoak");
    REQUIRE( m.getSymbol() == "☺");
    REQUIRE( m.getColor() == COLOR_YELLOW);
    REQUIRE( m.getDescription() == "Professor Oak: If you bring me a pokémon, I'll give you something truly special.");
}

TEST_CASE("overload constructor 1 sets Profoak Class variables", "[profoak][constructor]")
{
    Profoak m(5, 15);
    REQUIRE( m.getYPos() == 5);
    REQUIRE( m.getXPos() == 15);
    REQUIRE( m.getName() == "Professor Oak" );
    REQUIRE( m.getType() == "profoak");
    REQUIRE( m.getSymbol() == "☺");
    REQUIRE( m.getColor() == COLOR_YELLOW);
    REQUIRE( m.getDescription() == "Professor Oak: If you bring me a pokémon, I'll give you something truly special.");
}

TEST_CASE("set profoak type", "[profoak][set]")
{
    Profoak m;
    REQUIRE( m.getType() == "profoak");
    m.setType("");
    REQUIRE( m.getType() == "");
    m.setType("mMoOvVaABblE");
    REQUIRE( m.getType() == "mMoOvVaABblE");
}

TEST_CASE("set Profoak name", "[profoak][set]")
{
    Profoak m;
    REQUIRE ( m.getName() == "Professor Oak");
    m.setName("Professor Nope");
    REQUIRE ( m.getName() == "Professor Nope");
}

TEST_CASE("set profoak description", "[profoak][get][set]")
{
    Profoak m;
    REQUIRE (m.getDescription() == "Professor Oak: If you bring me a pokémon, I'll give you something truly special.");
    m.setDescription("What's a POKéMON?");
    REQUIRE (m.getDescription() == "What's a POKéMON?");
    m.setDescription("");
    REQUIRE (m.getDescription() == "");
}