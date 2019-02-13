#include "catch.hpp"
#include "Movable.hpp"
#include "Colors.hpp"

TEST_CASE("default constructor sets Movable Class variables", "[movable][constructor]")
{
    Movable m;
    REQUIRE( m.getName() == "boulder" );
    REQUIRE( m.getType() == "movable");
    REQUIRE( m.getSymbol() == 'M');
    REQUIRE( m.getColor() == COLOR_CYAN);
    REQUIRE( m.getDescription() == "This boulder is round-ish, maybe you can push it");
}

TEST_CASE("overload constructor 1 sets Movable Class variables", "[movable][constructor]")
{
    Movable m(5, 15);
    REQUIRE( m.getYPos() == 5);
    REQUIRE( m.getXPos() == 15);
    REQUIRE( m.getName() == "boulder" );
    REQUIRE( m.getType() == "movable");
    REQUIRE( m.getSymbol() == 'M');
    REQUIRE( m.getColor() == COLOR_CYAN);
    REQUIRE( m.getDescription() == "This boulder is round-ish, maybe you can push it");
}

TEST_CASE("overload constructor 2 sets Movable Class variables test with healing choice", "[movable][constructor]")
{
    Movable m(5, 15, COLOR_BLUE, 15, 1);
    REQUIRE( m.getYPos() == 5);
    REQUIRE( m.getXPos() == 15);
    REQUIRE( m.getName() == "boulder" );
    REQUIRE( m.getType() == "movable");
    REQUIRE( m.getSymbol() == 'M');
    REQUIRE( m.getColor() == COLOR_BLUE);
    REQUIRE( m.getDescription() == "This boulder is round-ish, maybe you can push it");
    REQUIRE( m.getHealing() == 15);
}

TEST_CASE("overload constructor 2 sets Movable Class variables test with damage choice", "[movable][constructor]")
{
    Movable m(5, 15, COLOR_BLUE, 15, 0);
    REQUIRE( m.getYPos() == 5);
    REQUIRE( m.getXPos() == 15);
    REQUIRE( m.getName() == "boulder" );
    REQUIRE( m.getType() == "movable");
    REQUIRE( m.getSymbol() == 'M');
    REQUIRE( m.getColor() == COLOR_BLUE);
    REQUIRE( m.getDescription() == "This boulder is round-ish, maybe you can push it");
    REQUIRE( m.getDamage() == 15);
}

TEST_CASE("set movable type", "[movable][set]")
{
    Movable m;
    REQUIRE( m.getType() == "movable");
    m.setType("");
    REQUIRE( m.getType() == "");
    m.setType("mMoOvVaABblE");
    REQUIRE( m.getType() == "mMoOvVaABblE");
}

TEST_CASE("set movable name", "[movable][set]")
{
    Movable m;
    REQUIRE ( m.getName() == "boulder");
    m.setName("bigger_boulder");
    REQUIRE ( m.getName() == "bigger_boulder");
}

TEST_CASE("set movable description", "[movable][get][set]")
{
    Movable m;
    REQUIRE (m.getDescription() == "This boulder is round-ish, maybe you can push it");
    m.setDescription("This boulder is square");
    REQUIRE (m.getDescription() == "This boulder is square");
    m.setDescription("");
    REQUIRE (m.getDescription() == "");
}

TEST_CASE("get and set damage", "[movable][get][set]")
{
    Movable m;
    REQUIRE (m.getDamage() == 0);
    m.setDamage(3);
    REQUIRE (m.getDamage() == 3);
    m.setDamage(6);
    REQUIRE (m.getDamage() == 6);
}

TEST_CASE("get and set movable object healing", "[movable][get][set]")
{
    Movable m;
    REQUIRE (m.getHealing() == 0);
    m.setHealing(3);
    REQUIRE (m.getHealing() == 3);
    m.setHealing(6);
    REQUIRE (m.getHealing() == 6);
}