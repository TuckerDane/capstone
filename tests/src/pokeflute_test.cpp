#include "catch.hpp"
#include "Pokeflute.hpp"
#include "Colors.hpp"

TEST_CASE("default constructor sets Pokeflute Class variables", "[pokeflute][constructor]")
{
    Pokeflute m;
    REQUIRE( m.getName() == "Poké Flute" );
    REQUIRE( m.getType() == "poke_flute");
    REQUIRE( m.getSymbol() == "ʃ");
    REQUIRE( m.getColor() == COLOR_YELLOW);
    REQUIRE( m.getDescription() == "Plays a pleasant melody that rouses Pokémon from sleep.");
}

TEST_CASE("overload constructor 1 sets Pokeflute Class variables", "[pokeflute][constructor]")
{
    Pokeflute m(5, 15);
    REQUIRE( m.getYPos() == 5);
    REQUIRE( m.getXPos() == 15);
    REQUIRE( m.getName() == "Poké Flute" );
    REQUIRE( m.getType() == "poke_flute");
    REQUIRE( m.getSymbol() == "ʃ");
    REQUIRE( m.getColor() == COLOR_YELLOW);
    REQUIRE( m.getDescription() == "Plays a pleasant melody that rouses Pokémon from sleep.");
}

TEST_CASE("set pokeflute type", "[pokeflute][set]")
{
    Pokeflute m;
    REQUIRE( m.getType() == "poke_flute");
    m.setType("");
    REQUIRE( m.getType() == "");
    m.setType("mMoOvVaABblE");
    REQUIRE( m.getType() == "mMoOvVaABblE");
}

TEST_CASE("set Pokeflute name", "[pokeflute][set]")
{
    Pokeflute m;
    REQUIRE ( m.getName() == "Poké Flute");
    m.setName("Repel");
    REQUIRE ( m.getName() == "Repel");
}

TEST_CASE("set pokeflute description", "[pokeflute][get][set]")
{
    Pokeflute m;
    REQUIRE (m.getDescription() == "Plays a pleasant melody that rouses Pokémon from sleep.");
    m.setDescription("What's a POKéMON?");
    REQUIRE (m.getDescription() == "What's a POKéMON?");
    m.setDescription("");
    REQUIRE (m.getDescription() == "");
}