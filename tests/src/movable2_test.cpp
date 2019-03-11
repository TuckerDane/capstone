#include "catch.hpp"
#include "Movable2.hpp"
#include "Colors.hpp"

TEST_CASE("default constructor sets Movable2 Class variables", "[movable2][constructor]")
{
    Movable2 m;
    REQUIRE( m.getName() == "boulder" );
    REQUIRE( m.getType() == "movable2");
    REQUIRE( m.getSymbol() == ".");
    REQUIRE( m.getColor() == COLOR_CYAN);
    REQUIRE( m.getDescription() == "This boulder is round-ish, maybe you can push it");
}

TEST_CASE("overload constructor 1 sets Movable2 Class variables", "[movable2][constructor]")
{
    Movable2 m(5, 15);
    REQUIRE( m.getYPos() == 5);
    REQUIRE( m.getXPos() == 15);
    REQUIRE( m.getName() == "boulder" );
    REQUIRE( m.getType() == "movable2");
    REQUIRE( m.getSymbol() == ".");
    REQUIRE( m.getColor() == COLOR_CYAN);
    REQUIRE( m.getDescription() == "This boulder is round-ish, maybe you can push it");
}

TEST_CASE("overload constructor 2 sets Movable2 Class variables test with healing choice", "[movable2][constructor]")
{
    Movable2 m(5, 15, COLOR_BLUE, 15, 1);
    REQUIRE( m.getYPos() == 5);
    REQUIRE( m.getXPos() == 15);
    REQUIRE( m.getName() == "boulder" );
    REQUIRE( m.getType() == "movable2");
    REQUIRE( m.getSymbol() == ".");
    REQUIRE( m.getColor() == COLOR_BLUE);
    REQUIRE( m.getDescription() == "This boulder is round-ish, maybe you can push it");
    REQUIRE( m.getHealing() == 15);
}

TEST_CASE("overload constructor 2 sets Movable2 Class variables test with damage choice", "[movable2][constructor]")
{
    Movable2 m(5, 15, COLOR_BLUE, 15, 0);
    REQUIRE( m.getYPos() == 5);
    REQUIRE( m.getXPos() == 15);
    REQUIRE( m.getName() == "boulder" );
    REQUIRE( m.getType() == "movable2");
    REQUIRE( m.getSymbol() == ".");
    REQUIRE( m.getColor() == COLOR_BLUE);
    REQUIRE( m.getDescription() == "This boulder is round-ish, maybe you can push it");
    REQUIRE( m.getDamage() == 15);
}

TEST_CASE("set Movable2 type", "[movable2][set]")
{
    Movable2 m;
    REQUIRE( m.getType() == "movable2");
    m.setType("");
    REQUIRE( m.getType() == "");
    m.setType("mMoOvVaABblE");
    REQUIRE( m.getType() == "mMoOvVaABblE");
}

TEST_CASE("set movable2 name", "[movable2][set]")
{
    Movable2 m;
    REQUIRE ( m.getName() == "boulder");
    m.setName("bigger_boulder");
    REQUIRE ( m.getName() == "bigger_boulder");
}

TEST_CASE("set movable2 description", "[movable2][get][set]")
{
    Movable2 m;
    REQUIRE (m.getDescription() == "This boulder is round-ish, maybe you can push it");
    m.setDescription("This boulder is square");
    REQUIRE (m.getDescription() == "This boulder is square");
    m.setDescription("");
    REQUIRE (m.getDescription() == "");
}

TEST_CASE("get and set movable2 damage", "[movable2][get][set]")
{
    Movable2 m;
    REQUIRE (m.getDamage() == 0);
    m.setDamage(3);
    REQUIRE (m.getDamage() == 3);
    m.setDamage(6);
    REQUIRE (m.getDamage() == 6);
}

TEST_CASE("get and set movable2 object healing", "[movable2][get][set]")
{
    Movable2 m;
    REQUIRE (m.getHealing() == 0);
    m.setHealing(3);
    REQUIRE (m.getHealing() == 3);
    m.setHealing(6);
    REQUIRE (m.getHealing() == 6);
}