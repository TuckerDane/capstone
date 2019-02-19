#include "catch.hpp"
#include "Softblock.hpp"
#include "Colors.hpp"

TEST_CASE("default constructor sets Soft Block Class variables", "[softblock][constructor]")
{
    Softblock im;
    REQUIRE( im.getName() == "Soft Block" );
    REQUIRE( im.getType() == "softblock");
    REQUIRE( im.getSymbol() == "█");
    REQUIRE( im.getColor() == COLOR_WHITE);
    REQUIRE( im.getDescription() == "This block looks pretty solid, but I bet it can still be blown to smithereens.");
}

TEST_CASE("overload constructor sets Soft Block Class variables", "[softblock][constructor]")
{
    Softblock im(5, 15);
    REQUIRE( im.getYPos() == 5);
    REQUIRE( im.getXPos() == 15);
    REQUIRE( im.getName() == "Soft Block" );
    REQUIRE( im.getType() == "softblock");
    REQUIRE( im.getSymbol() == "█");
    REQUIRE( im.getColor() == COLOR_WHITE);
    REQUIRE( im.getDescription() == "This block looks pretty solid, but I bet it can still be blown to smithereens.");
}

TEST_CASE("set soft block type", "[softblock][set]")
{
    Softblock im;
    REQUIRE( im.getType() == "softblock");
    im.setType("");
    REQUIRE( im.getType() == "");
    im.setType("mMoOvVaABblE");
    REQUIRE( im.getType() == "mMoOvVaABblE");
}

TEST_CASE("set soft block name", "[softblock][set]")
{
    Softblock im;
    REQUIRE ( im.getName() == "Soft Block");
    im.setName("bigger_block");
    REQUIRE ( im.getName() == "bigger_block");
}

TEST_CASE("set soft block description", "[softblock][get][set]")
{
    Softblock im;
    REQUIRE (im.getDescription() == "This block looks pretty solid, but I bet it can still be blown to smithereens.");
    im.setDescription("This block is square");
    REQUIRE (im.getDescription() == "This block is square");
    im.setDescription("");
    REQUIRE (im.getDescription() == "");
}