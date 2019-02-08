#include "catch.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include "Update.hpp"

TEST_CASE("player.move('w') key makes player position go from (x,y) to (x,y-1)", "[movement][UP]")
{
    Player p;
    int originalX = p.getXPos();
    int originalY = p.getYPos();
    p.move('w');
    REQUIRE( p.getXPos() == originalX );
    REQUIRE( p.getYPos() == (originalY - 1) );
}

TEST_CASE("isMoveAllowed at y-1 is false when there is a locked door", "[movement][UP]")
{
    Player p;
    Game g;
    Door(p.getYPos() - 1, p.getXPos(), -1, -1, -1, -1, true, COLOR_BLUE);
    REQUIRE(g.isMoveAllowed(p.getYPos() - 1, p.getXPos()) == false);
}   
    // unless there is a wall
    // unless there is an immovable object

TEST_CASE("player.move('a') makes player position go from (x,y) to (x-1,y)", "[movement][LEFT]")
{
    Player p;
    int originalX = p.getXPos();
    int originalY = p.getYPos();
    p.move('a');
    REQUIRE( p.getXPos() == (originalX - 1) );
    REQUIRE( p.getYPos() == (originalY) );
}

TEST_CASE("isMoveAllowed at x-1 does not allow player to move left when there is a locked door", "[movement][LEFT]")
{
    Player p;
    Game g;
    Door(p.getYPos(), p.getXPos()-1, -1, -1, -1, -1, true, COLOR_BLUE);
    REQUIRE(g.isMoveAllowed(p.getYPos(), p.getXPos()-1) == false);
}  

    // unless there is a wall
    // unless there is an immovable object

TEST_CASE("player.move('s') makes player position go from (x,y) to (x,y+1)", "[movement][DOWN]")
{
    Player p;
    int originalX = p.getXPos();
    int originalY = p.getYPos();
    p.move('s');
    REQUIRE( p.getXPos() == originalX );
    REQUIRE( p.getYPos() == (originalY + 1) );
}

TEST_CASE("isMoveAllowed at y+1 is false when there is a locked door", "[movement][DOWN]")
{
    Player p;
    Game g;
    Door(p.getYPos() + 1, p.getXPos(), -1, -1, -1, -1, true, COLOR_BLUE);
    REQUIRE(g.isMoveAllowed(p.getYPos() + 1, p.getXPos()) == false);
} 
    
    // unless there is a wall
    // unless there is an immovable object

TEST_CASE("player.move('d') makes player position go from (x,y) to (x+1,y)", "[movement][RIGHT]")
{
    Player p;
    int originalX = p.getXPos();
    int originalY = p.getYPos();
    p.move('d');
    REQUIRE( p.getXPos() == (originalX + 1) );
    REQUIRE( p.getYPos() == (originalY) );
}

TEST_CASE("isMoveAllowed at x+1 does not allow player to move left when there is a locked door", "[movement][RIGHT]")
{
    Player p;
    Game g;
    Door(p.getYPos(), p.getXPos()+1, -1, -1, -1, -1, true, COLOR_BLUE);
    REQUIRE(g.isMoveAllowed(p.getYPos(), p.getXPos()+1) == false);
}  

    // unless there is a locked door
    // unless there is a wall
    // unless there is an immovable object



