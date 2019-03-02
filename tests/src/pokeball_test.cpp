#include "catch.hpp"
#include "Pokeball.hpp"
#include "Colors.hpp"

TEST_CASE("default constructor sets Pokeball Class variables", "[pokeball][constructor]")
{
    Pokeball m;
    REQUIRE( m.getName() == "Poké Ball" );
    REQUIRE( m.getType() == "poke_ball");
    REQUIRE( m.getSymbol() == "ɵ");
    REQUIRE( m.getColor() == COLOR_RED);
    REQUIRE( m.getDescription() == "A Ball thrown at wild Pokémon to catch them.");
}

TEST_CASE("overload constructor 1 sets Pokeball Class variables", "[pokeball][constructor]")
{
    Pokeball m(5, 15);
    REQUIRE( m.getYPos() == 5);
    REQUIRE( m.getXPos() == 15);
    REQUIRE( m.getName() == "Poké Ball" );
    REQUIRE( m.getType() == "poke_ball");
    REQUIRE( m.getSymbol() == "ɵ");
    REQUIRE( m.getColor() == COLOR_RED);
    REQUIRE( m.getDescription() == "A Ball thrown at wild Pokémon to catch them.");
}

TEST_CASE("set pokeball type", "[pokeball][set]")
{
    Pokeball m;
    REQUIRE( m.getType() == "poke_ball");
    m.setType("");
    REQUIRE( m.getType() == "");
    m.setType("mMoOvVaABblE");
    REQUIRE( m.getType() == "mMoOvVaABblE");
}

TEST_CASE("set Pokeball name", "[pokeball][set]")
{
    Pokeball m;
    REQUIRE ( m.getName() == "Poké Ball");
    m.setName("Repel");
    REQUIRE ( m.getName() == "Repel");
}

TEST_CASE("set pokeball description", "[pokeball][get][set]")
{
    Pokeball m;
    REQUIRE (m.getDescription() == "A Ball thrown at wild Pokémon to catch them.");
    m.setDescription("What's a POKéMON?");
    REQUIRE (m.getDescription() == "What's a POKéMON?");
    m.setDescription("");
    REQUIRE (m.getDescription() == "");
}