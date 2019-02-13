#include "catch.hpp"
#include "Immovable.hpp"
#include "Colors.hpp"

TEST_CASE("default constructor sets Immovable Class variables", "[immovable][constructor]")
{
    Immovable im;
    REQUIRE( im.getName() == "pillar" );
    REQUIRE( im.getType() == "immovable");
    REQUIRE( im.getSymbol() == 'O');
    REQUIRE( im.getColor() == COLOR_WHITE);
    REQUIRE( im.getDescription() == "This is a pillar, looks like those used in important buildings.");
}

TEST_CASE("overload constructor sets Immovable Class variables", "[immovable][constructor]")
{
    Immovable im(5, 15);
    REQUIRE( im.getYPos() == 5);
    REQUIRE( im.getXPos() == 15);
    REQUIRE( im.getName() == "pillar" );
    REQUIRE( im.getType() == "immovable");
    REQUIRE( im.getSymbol() == 'O');
    REQUIRE( im.getColor() == COLOR_WHITE);
    REQUIRE( im.getDescription() == "This is a pillar, looks like those used in important buildings.");
}

TEST_CASE("set immovable type", "[immovable][set]")
{
    Immovable im;
    REQUIRE( im.getType() == "immovable");
    im.setType("");
    REQUIRE( im.getType() == "");
    im.setType("mMoOvVaABblE");
    REQUIRE( im.getType() == "mMoOvVaABblE");
}

TEST_CASE("set immovable name", "[immovable][set]")
{
    Immovable im;
    REQUIRE ( im.getName() == "pillar");
    im.setName("bigger_boulder");
    REQUIRE ( im.getName() == "bigger_boulder");
}

TEST_CASE("set immovable description", "[immovable][get][set]")
{
    Immovable im;
    REQUIRE (im.getDescription() == "This is a pillar, looks like those used in important buildings.");
    im.setDescription("This boulder is square");
    REQUIRE (im.getDescription() == "This boulder is square");
    im.setDescription("");
    REQUIRE (im.getDescription() == "");
}