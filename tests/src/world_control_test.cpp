#include "catch.hpp"
#include "Player.hpp"
#include "../../src/game_objects/Player.cpp"

//SKELETON
// TEST_CASE("TEST CASE DESCRIPTION HERE", "[KEYWORD]")
// {
    //Key k;
    // REQUIRE( k.getType() == "key" );
    // REQUIRE( k.getName() == "normal key");
    // REQUIRE( k.getPassword() == -1);
    // REQUIRE( k.getWeight() == 1);
    // REQUIRE( k.getDescription() == "used to unlock doors");
// }

// Test if w || W || KEY_UP, player moves up
TEST_CASE("w key makes player position go from (x,y) to (x,y-1)", "[movement][UP]")
{
    Player p;
    int originalX = p.getXPos();
    int originalY = p.getYPos();

    p.move('w');
    REQUIRE( p.getXPos() == originalX );
    REQUIRE( p.getYPos() == (originalY - 1) );
}
    
    // unless there is a locked door
    // unless there is a wall
    // unless there is an immovable object


// Test if a || A || KEY_LEFT, player moves left (3 SEPERATE TESTS PER KEY)
TEST_CASE("a key makes player position go from (x,y) to (x-1,y)", "[movement][LEFT]")
{
    Player p;
    int originalX = p.getXPos();
    int originalY = p.getYPos();

    p.move('a');
    REQUIRE( p.getXPos() == (originalX - 1) );
    REQUIRE( p.getYPos() == (originalY) );
}

    // unless there is a locked door
    // unless there is a wall
    // unless there is an immovable object



// Test if s || S || KEY_DOWN, player moves down (3 SEPERATE TESTS PER KEY)
TEST_CASE("s key makes player position go from (x,y) to (x,y+1)", "[movement][DOWN]")
{
    Player p;
    int originalX = p.getXPos();
    int originalY = p.getYPos();

    p.move('s');
    REQUIRE( p.getXPos() == originalX );
    REQUIRE( p.getYPos() == (originalY + 1) );
}

    // unless there is a locked door
    // unless there is a wall
    // unless there is an immovable object



// Test if d || D || KEY_RIGHT, player moves right (3 SEPERATE TESTS PER KEY)
TEST_CASE("d key makes player position go from (x,y) to (x+1,y)", "[movement][RIGHT]")
{
    Player p;
    int originalX = p.getXPos();
    int originalY = p.getYPos();

    p.move('d');
    REQUIRE( p.getXPos() == (originalX + 1) );
    REQUIRE( p.getYPos() == (originalY) );
}

    // unless there is a locked door
    // unless there is a wall
    // unless there is an immovable object



