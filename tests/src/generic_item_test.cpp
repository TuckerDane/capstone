#include "catch.hpp"
#include "Item.hpp"
#include "Object.hpp"
#include "Door.hpp"

TEST_CASE( "default constructor sets Generic Item Class variables", "[item][constructor]")
{
    Item it;
    REQUIRE( it.getWeight() == 0);
}

TEST_CASE( "set / get Item Generic Class weight", "[item][set][get]")
{
    Item it;
    REQUIRE( it.getWeight() == 0);
    it.setWeight(5);
    REQUIRE( it.getWeight() == 5);
    it.setWeight(-50);
    REQUIRE( it.getWeight() == -50);
}

TEST_CASE( "set / get Item Generic Class damage", "[item][set][get]")
{
    Item it;
    it.setDamage(0);
    REQUIRE( it.getDamage() == 0);
    it.setDamage(5);
    REQUIRE( it.getDamage() == 5);
    it.setDamage(-50);
    REQUIRE( it.getDamage() == -50);
}

TEST_CASE( "set / get Item Generic Class healing", "[item][set][get]")
{
    Item it;
    it.setHealing(0);
    REQUIRE( it.getHealing() == 0);
    it.setHealing(5);
    REQUIRE( it.getHealing() == 5);
    it.setHealing(-50);
    REQUIRE( it.getHealing() == -50);
}

TEST_CASE( "test use on Item Generic Class", "[item][set][get]")
{
    Item it;
    REQUIRE( it.use() == false);
}