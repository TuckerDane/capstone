#include "catch.hpp"
#include "Player.hpp"

TEST_CASE("default constructor", "[player][constructor]")
{
	Player p;
	REQUIRE(p.getNumItems() == 0);
	REQUIRE(p.getCurrentRoom() == 0);
	REQUIRE(p.getIsMoved() == false);
	REQUIRE(p.getSelectedItemIndex() == 0);
	REQUIRE(p.getEquippedItemIndex() == 0);
	REQUIRE(p.getHP() == 10);
	REQUIRE(p.getMaxHP() == 10);
	REQUIRE(p.getCurrentCarryWeight() == 0);
	REQUIRE(p.getMaxCarryWeight() == 10);
}

TEST_CASE("set/get maxCarryWeight", "[player][get][set]")
{
	Player p;
	REQUIRE(p.getMaxCarryWeight() == 10);
	p.setMaxCarryWeight(15);
	REQUIRE(p.getMaxCarryWeight() == 15);
	p.setMaxCarryWeight(100);
	REQUIRE(p.getMaxCarryWeight() == 100);
}

TEST_CASE("set/get currentCarryWeight", "[player][get][set]")
{
	Player p;
	REQUIRE(p.getCurrentCarryWeight() == 0);
	p.setCurrentCarryWeight(15);					
	REQUIRE(p.getCurrentCarryWeight() == 15);	//returns 0 == 15
	p.setCurrentCarryWeight(100);
	REQUIRE(p.getCurrentCarryWeight() == 100);  //returns 0 == 100
}

TEST_CASE("set/get numItems", "[player][get][set]")
{
	Player p;
	REQUIRE(p.getNumItems() == 0);
	p.setNumItems(15);
	REQUIRE(p.getNumItems() == 15);
	p.setNumItems(100);
	REQUIRE(p.getNumItems() == 100);
}

TEST_CASE("set/get currentRoom", "[player][get][set]")
{
	Player p;
	REQUIRE(p.getCurrentRoom() == 0);
	p.setCurrentRoom(1);
	REQUIRE(p.getCurrentRoom() == 1);
	p.setCurrentRoom(2);
	REQUIRE(p.getCurrentRoom() == 2);
}

TEST_CASE("set/get selectedItemIndex", "[player][get][set]")
{
	Player p;
	REQUIRE(p.getSelectedItemIndex() == 0);
	p.setSelectedItemIndex(1);
	REQUIRE(p.getSelectedItemIndex() == 1);
	p.setSelectedItemIndex(2);
	REQUIRE(p.getSelectedItemIndex() == 2);
}

TEST_CASE("set/get equippedItemIndex", "[player][get][set]")
{
	Player p;
	REQUIRE(p.getEquippedItemIndex() == 0);
	p.setEquippedItemIndex(1);
	REQUIRE(p.getEquippedItemIndex() == 1);
	p.setEquippedItemIndex(2);
	REQUIRE(p.getEquippedItemIndex() == 2);
}

TEST_CASE("set/get isMoved", "[player][get][set]")
{
	Player p;
	REQUIRE(p.getIsMoved() == false);
	p.setIsMoved(true);
	REQUIRE(p.getIsMoved() == true);
	p.setIsMoved(false);
	REQUIRE(p.getIsMoved() == false);
}

TEST_CASE("set/get HP", "[player][get][set]")
{
	Player p;
	REQUIRE(p.getHP() == 10);
	p.setHP(20);
	REQUIRE(p.getHP() == 20);
	p.setHP(25);
	REQUIRE(p.getHP() == 25);
}

TEST_CASE("set/get maxHP", "[player][get][set]")
{
	Player p;
	REQUIRE(p.getMaxHP() == 10);
	p.setMaxHP(25);
	REQUIRE(p.getMaxHP() == 25);
	p.setMaxHP(50);
	REQUIRE(p.getMaxHP() == 50);
}
