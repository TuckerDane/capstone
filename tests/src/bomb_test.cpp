#include "catch.hpp"
#include "Bomb.hpp"
#include "Colors.hpp"

TEST_CASE("default constructor sets Bomb Class variables", "[bomb][constructor]")
{
    Bomb m;
    REQUIRE( m.getName() == "Bomberman Bomb" );
    REQUIRE( m.getType() == "bomb");
    REQUIRE( m.getSymbol() == "Ỏ");
    REQUIRE( m.getColor() == COLOR_RED);
    REQUIRE( m.getDescription() == "Creates an explosion in a + shape. Don't forget to duck for cover!");
}

TEST_CASE("overload constructor 1 sets Bomb Class variables", "[bomb][constructor]")
{
    Bomb m(5, 15);
    REQUIRE( m.getYPos() == 5);
    REQUIRE( m.getXPos() == 15);
    REQUIRE( m.getName() == "Bomberman Bomb" );
    REQUIRE( m.getType() == "bomb");
    REQUIRE( m.getSymbol() == "Ỏ");
    REQUIRE( m.getColor() == COLOR_RED);
    REQUIRE( m.getDescription() == "Creates an explosion in a + shape. Don't forget to duck for cover!");
}

TEST_CASE("set bomb type", "[bomb][set]")
{
    Bomb m;
    REQUIRE( m.getType() == "bomb");
    m.setType("");
    REQUIRE( m.getType() == "");
    m.setType("mMoOvVaABblE");
    REQUIRE( m.getType() == "mMoOvVaABblE");
}

TEST_CASE("set bomb name", "[bomb][set]")
{
    Bomb m;
    REQUIRE ( m.getName() == "Bomberman Bomb");
    m.setName("bigger_bomb");
    REQUIRE ( m.getName() == "bigger_bomb");
}

TEST_CASE("set bomb description", "[bomb][get][set]")
{
    Bomb m;
    REQUIRE (m.getDescription() == "Creates an explosion in a + shape. Don't forget to duck for cover!");
    m.setDescription("This bomb doesn't go bang");
    REQUIRE (m.getDescription() == "This bomb doesn't go bang");
    m.setDescription("");
    REQUIRE (m.getDescription() == "");
}

TEST_CASE("get and set bomb damage", "[bomb][get][set]")
{
    Bomb m;
    REQUIRE (m.getDamage() == 2);
    m.setDamage(3);
    REQUIRE (m.getDamage() == 3);
    m.setDamage(6);
    REQUIRE (m.getDamage() == 6);
}