#include "catch.hpp"
#include "Player.hpp"

TEST_CASE("w key makes player position go from (x,y) to (x,y-1)", "[movement][UP]")
{
    Player p;
    int originalX = p.getXPos();
    int originalY = p.getYPos();

    p.move('w');
    REQUIRE( p.getXPos() == originalX );
    REQUIRE( p.getYPos() == (originalY - 1) );
}
    
TEST_CASE("a key makes player position go from (x,y) to (x-1,y)", "[movement][LEFT]")
{
    Player p;
    int originalX = p.getXPos();
    int originalY = p.getYPos();

    p.move('a');
    REQUIRE( p.getXPos() == (originalX - 1) );
    REQUIRE( p.getYPos() == (originalY) );
}

TEST_CASE("s key makes player position go from (x,y) to (x,y+1)", "[movement][DOWN]")
{
    Player p;
    int originalX = p.getXPos();
    int originalY = p.getYPos();

    p.move('s');
    REQUIRE( p.getXPos() == originalX );
    REQUIRE( p.getYPos() == (originalY + 1) );
}

TEST_CASE("d key makes player position go from (x,y) to (x+1,y)", "[movement][RIGHT]")
{
    Player p;
    int originalX = p.getXPos();
    int originalY = p.getYPos();

    p.move('d');
    REQUIRE( p.getXPos() == (originalX + 1) );
    REQUIRE( p.getYPos() == (originalY) );
}



