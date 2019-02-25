#include "catch.hpp"
#include "Object.hpp"
#include "Colors.hpp"

TEST_CASE("default constructor sets Object Class variables", "[object][constructor]")
{
    Object o;
    REQUIRE( o.getXPos() == 0);
    REQUIRE( o.getYPos() == 0);
    REQUIRE( o.getName() == "unnamed" );
    REQUIRE( o.getType() == "generic_object");
    REQUIRE( o.getSymbol() == "?");
    REQUIRE( o.getColor() == COLOR_BLACK);
    REQUIRE( o.getDescription() == "none");
}

TEST_CASE("overload constructor sets Object Class variables test", "[object][constructor]")
{
    Object o(20, 35, COLOR_CYAN, "!", "test_type", "test_name", "test_description");
    REQUIRE( o.getYPos() == 35);
    REQUIRE( o.getXPos() == 20);
    REQUIRE( o.getName() == "test_name" );
    REQUIRE( o.getType() == "test_type");
    REQUIRE( o.getSymbol() == "!");
    REQUIRE( o.getColor() == COLOR_CYAN);
    REQUIRE( o.getDescription() == "test_description");
}

TEST_CASE("set object XPos", "[object][set]")
{
    Object o;
    REQUIRE( o.getXPos() == 0);
    o.setXPos(25);
    REQUIRE( o.getXPos() == 25);
    o.setXPos(-50);
    REQUIRE( o.getXPos() == -50);
}

TEST_CASE("set object YPos", "[object][set]")
{
    Object o;
    REQUIRE( o.getYPos() == 0);
    o.setYPos(25);
    REQUIRE( o.getYPos() == 25);
    o.setYPos(-50);
    REQUIRE( o.getYPos() == -50);
}

TEST_CASE("set object symbol", "[object][set]")
{
    Object o;
    REQUIRE( o.getSymbol() == "?");
    o.setSymbol("!");
    REQUIRE( o.getSymbol() == "!");
    o.setSymbol("@");
    REQUIRE( o.getSymbol() == "@");
}

TEST_CASE("set object type", "[object][set]")
{
    Object o;
    REQUIRE( o.getType() == "generic_object");
    o.setType("");
    REQUIRE( o.getType() == "");
    o.setType("objective");
    REQUIRE( o.getType() == "objective");
}

TEST_CASE("set object name", "[object][set]")
{
    Object o;
    REQUIRE ( o.getName() == "unnamed");
    o.setName("no_name");
    REQUIRE ( o.getName() == "no_name");
}

TEST_CASE("set object description", "[object][get][set]")
{
    Object o;
    REQUIRE ( o.getDescription() == "none");
    o.setDescription("Still none");
    REQUIRE ( o.getDescription() == "Still none");
    o.setDescription("");
    REQUIRE ( o.getDescription() == "");
}

TEST_CASE("set object color", "[object][get][set]")
{
    Object o;
    REQUIRE ( o.getColor() == COLOR_BLACK);
    o.setColor(COLOR_CYAN);
    REQUIRE ( o.getColor() == COLOR_CYAN);
    o.setColor(COLOR_BLUE);
    REQUIRE ( o.getColor() == COLOR_BLUE);
}

TEST_CASE("test red color pairs", "[object][colors]")
{
    Object o;
    REQUIRE ( o.setColorPair(COLOR_RED, COLOR_BLACK) == RED_ON_BLACK);
    REQUIRE ( o.setColorPair(COLOR_RED, COLOR_BLUE) == RED_ON_BLUE);
    REQUIRE ( o.setColorPair(COLOR_RED, COLOR_CYAN) == 0);
}

TEST_CASE("test green color pairs", "[object][colors]")
{
    Object o;
    REQUIRE ( o.setColorPair(COLOR_GREEN, COLOR_BLACK) == GREEN_ON_BLACK);
    REQUIRE ( o.setColorPair(COLOR_GREEN, COLOR_BLUE) == GREEN_ON_BLUE);
    REQUIRE ( o.setColorPair(COLOR_GREEN, COLOR_CYAN) == 0);
}

TEST_CASE("test yellow color pairs", "[object][colors]")
{
    Object o;
    REQUIRE ( o.setColorPair(COLOR_YELLOW, COLOR_BLACK) == YELLOW_ON_BLACK);
    REQUIRE ( o.setColorPair(COLOR_YELLOW, COLOR_BLUE) == YELLOW_ON_BLUE);
    REQUIRE ( o.setColorPair(COLOR_YELLOW, COLOR_CYAN) == 0);
}

TEST_CASE("test blue color pairs", "[object][colors]")
{
    Object o;
    REQUIRE ( o.setColorPair(COLOR_BLUE, COLOR_BLACK) == BLUE_ON_BLACK);
    REQUIRE ( o.setColorPair(COLOR_BLUE, COLOR_BLUE) == BLUE_ON_BLACK); // TODO: Figure out what to do in this case
    REQUIRE ( o.setColorPair(COLOR_BLUE, COLOR_CYAN) == 0);
}

TEST_CASE("test magenta color pairs", "[object][colors]")
{
    Object o;
    REQUIRE ( o.setColorPair(COLOR_MAGENTA, COLOR_BLACK) == MAGENTA_ON_BLACK);
    REQUIRE ( o.setColorPair(COLOR_MAGENTA, COLOR_BLUE) == MAGENTA_ON_BLUE); 
    REQUIRE ( o.setColorPair(COLOR_MAGENTA, COLOR_CYAN) == 0);
}

TEST_CASE("test cyan color pairs", "[object][colors]")
{
    Object o;
    REQUIRE ( o.setColorPair(COLOR_CYAN, COLOR_BLACK) == CYAN_ON_BLACK); 
    REQUIRE ( o.setColorPair(COLOR_CYAN, COLOR_BLUE) == CYAN_ON_BLUE);
    REQUIRE ( o.setColorPair(COLOR_CYAN, COLOR_CYAN) == 0);
}

TEST_CASE("test white color pairs", "[object][colors]")
{
    Object o;
    REQUIRE ( o.setColorPair(COLOR_WHITE, COLOR_BLACK) == WHITE_ON_BLACK);
    REQUIRE ( o.setColorPair(COLOR_WHITE, COLOR_BLUE) == WHITE_ON_BLUE);
    REQUIRE ( o.setColorPair(COLOR_WHITE, COLOR_CYAN) == 0);
}

TEST_CASE("test unknown color pairs", "[object][colors]")
{
    Object o;
    REQUIRE ( o.setColorPair(151, COLOR_BLACK) == 0);
    REQUIRE ( o.setColorPair(151, COLOR_BLUE) == 0);
    REQUIRE ( o.setColorPair(151, COLOR_CYAN) == 0);
}