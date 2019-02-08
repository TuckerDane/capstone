#include "catch.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include "Update.hpp"

TEST_CASE("player.move('w') makes player position go from (x,y) to (x,y-1)", "[movement][UP]")
{
    Player p;
    int originalX = p.getXPos();
    int originalY = p.getYPos();
    p.move('w');
    REQUIRE( p.getXPos() == originalX );
    REQUIRE( p.getYPos() == (originalY - 1) );
}

TEST_CASE("player.move('w') makes player position go from (x,y) to (x,y-1) when y-1 has a movable object", "[movement][UP]")
{
    Player p;
    int originalX = p.getXPos();
    int originalY = p.getYPos();
    Movable(originalY-1, originalX);
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

TEST_CASE("isMoveAllowed at y-1 is false when there is an immovable object", "[movement][UP]")
{
    Player p;
    Game g;
    Immovable(p.getYPos() - 1, p.getXPos());    
    REQUIRE(g.isMoveAllowed(p.getYPos() - 1, p.getXPos()) == false);
} 


    // TODO: unless there is a wall '-' '|' '\\' '/' '+'


TEST_CASE("player.move('a') makes player position go from (x,y) to (x-1,y)", "[movement][LEFT]")
{
    Player p;
    int originalX = p.getXPos();
    int originalY = p.getYPos();
    p.move('a');
    REQUIRE( p.getXPos() == (originalX - 1) );
    REQUIRE( p.getYPos() == originalY );
}

TEST_CASE("player.move('a') makes player position go from (x,y) to (x-1,y) when x-1 has a movable object", "[movement][LEFT]")
{
    Player p;
    int originalX = p.getXPos();
    int originalY = p.getYPos();
    Movable(originalY, originalX-1);
    p.move('a');
    REQUIRE( p.getXPos() == (originalX - 1) );
    REQUIRE( p.getYPos() == originalY );
}

TEST_CASE("isMoveAllowed at x-1 does not allow player to move left when there is a locked door", "[movement][LEFT]")
{
    Player p;
    Game g;
    Door(p.getYPos(), p.getXPos()-1, -1, -1, -1, -1, true, COLOR_BLUE);
    REQUIRE(g.isMoveAllowed(p.getYPos(), p.getXPos()-1) == false);
}  

TEST_CASE("isMoveAllowed at x-1 is false when there is an immovable object", "[movement][LEFT]")
{
    Player p;
    Game g;
    Immovable(p.getYPos(), p.getXPos()-1);
    REQUIRE(g.isMoveAllowed(p.getYPos(), p.getXPos()-1) == false);
} 


    // TODO: unless there is a wall '-' '|' '\\' '/' '+'


TEST_CASE("player.move('s') makes player position go from (x,y) to (x,y+1)", "[movement][DOWN]")
{
    Player p;
    int originalX = p.getXPos();
    int originalY = p.getYPos();
    p.move('s');
    REQUIRE( p.getXPos() == originalX );
    REQUIRE( p.getYPos() == (originalY + 1) );
}

TEST_CASE("player.move('s') makes player position go from (x,y) to (x,y+1) when y+1 has a movable object", "[movement][DOWN]")
{
    Player p;
    int originalX = p.getXPos();
    int originalY = p.getYPos();
    Movable(originalY+1, originalX);
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

TEST_CASE("isMoveAllowed at y+1 is false when there is an immovable object", "[movement][DOWN]")
{
    Player p;
    Game g;
    Immovable(p.getYPos() + 1, p.getXPos());
    REQUIRE(g.isMoveAllowed(p.getYPos()+1, p.getXPos()) == false);
} 

    // TODO: unless there is a wall '-' '|' '\\' '/' '+'


TEST_CASE("player.move('d') makes player position go from (x,y) to (x+1,y)", "[movement][RIGHT]")
{
    Player p;
    int originalX = p.getXPos();
    int originalY = p.getYPos();
    p.move('d');
    REQUIRE( p.getXPos() == (originalX + 1) );
    REQUIRE( p.getYPos() == (originalY) );
}

TEST_CASE("player.move('d') makes player position go from (x,y) to (x+1,y) when x+1 has a movable object", "[movement][RIGHT]")
{
    Player p;
    int originalX = p.getXPos();
    int originalY = p.getYPos();
    Movable(originalY, originalX+1);
    p.move('d');
    REQUIRE( p.getXPos() == (originalX + 1) );
    REQUIRE( p.getYPos() == originalY );
}

TEST_CASE("isMoveAllowed at x+1 does not allow player to move left when there is a locked door", "[movement][RIGHT]")
{
    Player p;
    Game g;
    Door(p.getYPos(), p.getXPos()+1, -1, -1, -1, -1, true, COLOR_BLUE);
    REQUIRE(g.isMoveAllowed(p.getYPos(), p.getXPos()+1) == false);
}  

TEST_CASE("isMoveAllowed at x+1 is false when there is an immovable object", "[movement][RIGHT]")
{
    Player p;
    Game g;
    Immovable(p.getYPos(), p.getXPos()+1);
    REQUIRE(g.isMoveAllowed(p.getYPos(), p.getXPos()+1) == false);
} 

    // TODO: unless there is a wall '-' '|' '\\' '/' '+'




