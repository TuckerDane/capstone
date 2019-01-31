#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Key.hpp"
#include "Item.hpp"
#include "Object.hpp"
#include "../../src/game_objects/Key.cpp"
#include "../../src/game_objects/Item.cpp"
#include "../../src/game_objects/Object.cpp"
#include "../../src/game_objects/Door.cpp"

TEST_CASE("default constructor sets Key Class variables", "[Key]")
{
    Key k;
    REQUIRE( k.getType() == "key" );
    REQUIRE( k.getName() == "normal key");
    REQUIRE( k.getPassword() == -1);
    REQUIRE( k.getWeight() == 1);
    REQUIRE( k.getDescription() == "used to unlock doors");
}

TEST_CASE("overload constructor sets Key Class variables", "[Key]")
{
    Key k("keyname", 1);
    REQUIRE( k.getType() == "key" );
    REQUIRE( k.getName() == "keyname");
    REQUIRE( k.getPassword() == 1);
    REQUIRE( k.getWeight() == 1);
    REQUIRE( k.getDescription() == "used to unlock doors");   
}

TEST_CASE("set Key password", "[key][set]")
{
    Key k;
    REQUIRE( k.getPassword() == -1);
    k.setPassword(5);
    REQUIRE( k.getPassword() == 5);
    k.setPassword(0);
    REQUIRE( k.getPassword() == 0);
    k.setPassword(-7);
    REQUIRE( k.getPassword() == -7);
}

TEST_CASE("set Key type", "[key][set]")
{
    Key k;
    REQUIRE( k.getType() == "key");
    k.setType("");
    REQUIRE( k.getType() == "");
    k.setType("THEKEYOFTRUTH");
    REQUIRE( k.getType() == "THEKEYOFTRUTH");
}

TEST_CASE("set Key name", "[key][set]")
{
    Key k;
    REQUIRE ( k.getName() == "normal key");
    k.setName("green key");
    REQUIRE ( k.getName() == "green key");
}

TEST_CASE("set Key weight", "[key][get][set]")
{
    Key k;
    REQUIRE (k.getWeight() == 1 );
    k.setWeight(20);
    REQUIRE (k.getWeight() == 20);
    k.setWeight(0);
    REQUIRE (k.getWeight() == 0);
    k.setWeight(-49);
    REQUIRE (k.getWeight() == -49);
}

TEST_CASE("set Key description", "[key][get][set]")
{
    Key k;
    REQUIRE (k.getDescription() == "used to unlock doors");
    k.setDescription("used to unlock the green door");
    REQUIRE (k.getDescription() == "used to unlock the green door");
    k.setDescription("");
    REQUIRE (k.getDescription() == "");
}

TEST_CASE("use Key to lock and unlock door success", "[key]")
{
    Key k;
    Door d;
    
    k.setPassword(2);
    d.setPassword(2);
    d.setLocked(true);

    k.use(&d);
    REQUIRE (d.getLocked() == false);
    k.use(&d);
    REQUIRE (d.getLocked() == true);
}

TEST_CASE("use Key fails to lock door with wrong password", "[key]")
{
    Key k;
    Door d;

    k.setPassword(1);

    d.setPassword(2); 
    d.setLocked(false);

    k.use(&d);
    REQUIRE (d.getLocked() == false);
}

TEST_CASE("use Key fails to unlock door with wrong password", "[key]")
{
    Key k;
    Door d;

    k.setPassword(1);

    d.setPassword(2);
    d.setLocked(true);

    k.use(&d);
    REQUIRE (d.getLocked() == true);
}