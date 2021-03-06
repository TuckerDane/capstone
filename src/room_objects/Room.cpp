/* ..............................................
  @ file Room.cpp
  @ Authors: Tucker Walker, David Pipitone, Marisa Rea
  @ OSU Computer Science - Capstone Project
  @ Winter Term 2019
  
  
.............................................. */
#include "Room.hpp"

/* ..............................................
  CONSTRUCTORS/DECONSTRUCTORS 
  
.............................................. */

Room::Room()
{
    setWalls("rooms/generic.room");
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        items[i] = NULL;
    }
    for (int i = 0; i < MAX_DOORS; i++)
    {
        doors[i] = NULL;
    }
    for (int i = 0; i < MAX_TELEPORTERS; i++)
    {
	teleporters[i] = NULL;
    }
    type = "Room";
    name = "Generic Room";
    description = "A generic room";
    itemsArrayIndex = 0;
    tileColor = 0;
}

Room::Room(string roomFile)
{
    setWalls(roomFile);
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        items[i] = NULL;
    }
    for (int i = 0; i < MAX_DOORS; i++)
    {
        doors[i] = NULL;
    }
    for (int i = 0; i < MAX_TELEPORTERS; i++)
    {
	teleporters[i] = NULL;
    }
    type = "Room";
    name = "Generic Room";
    description = "A generic room";
    itemsArrayIndex = 0;
    tileColor = 0;
}

Room::~Room()
{
    for (int i = 0; i < MAX_DOORS; i++)
    {
        if (doors[i] != NULL)
        {
            delete doors[i];
        }
    }
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if (items[i] != NULL)
        {
            delete items[i];
        }
    }
    for (int i = 0; i < MAX_TELEPORTERS; i++)
    {
        if (teleporters[i] != NULL)
        {
            delete teleporters[i];
        }
    }
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        if (enemies[i] != NULL)
        {
            delete enemies[i];
        }
    }
}

/* ..............................................
  SETTERS 
  
.............................................. */

void Room::setWalls(string roomFile)
{
    int width = 0;
    int height = 0;
    char c;
    fstream file;
    file.open(roomFile, fstream::in);
    if (file.is_open())
    {
        file.get(c);
        while (file.good())
        {
            if (c != '\n')
            {
                walls[height][width] = c;
                width++;
            }
            else
            {
                width = 0;
                height++;
            }
            file.get(c);
        }
    }
    file.close();
}

void Room::setItem(Item *item, int itemIndex)
{
    items[itemIndex] = item;
    this->itemsArrayIndex++;
}

void Room::setType(string type)
{
    this->type = type;
}

void Room::setName(string name)
{
    this->name = name;
}

void Room::setDescription(string description)
{
    this->description = description;
}

void Room::setDoor(Door *door, int doorIndex)
{
    doors[doorIndex] = door;
}

void Room::setEnemy(Enemy *enemy, int enemyIndex)
{
    enemies[enemyIndex] = enemy;
}

void Room::setTeleporter(Teleporter *teleporter, int teleporterIndex)
{
    teleporters[teleporterIndex] = teleporter;
}

void Room::setTileColor(int tileColor)
{
    this->tileColor = tileColor;
}

/* ..............................................
  GETTERS 
  
.............................................. */

int Room::getMaxHeight()
{
    return MAX_HEIGHT;
}

int Room::getMaxWidth()
{
    return MAX_WIDTH;
}

int Room::getMaxItems()
{
    return MAX_ITEMS;
}

int Room::getMaxDoors()
{
    return MAX_DOORS;
}

int Room::getMaxTeleporters()
{
    return MAX_TELEPORTERS;
}

int Room::getMaxEnemies()
{
    return MAX_ENEMIES;
}

char Room::getWall(int height, int width)
{
    return walls[height][width];
}

Item **Room::getItems()
{
    return items;
}

Item *Room::getItem(int itemIndex)
{
    return items[itemIndex];
}

string Room::getType()
{
    return type;
}

string Room::getName()
{
    return name;
}

string Room::getDescription()
{
    return description;
}

Door *Room::getDoor(int doorIndex)
{
    return doors[doorIndex];
}

Door **Room::getDoors()
{
    return doors;
}

Enemy **Room::getEnemies()
{
    return enemies;
}

Teleporter *Room::getTeleporter(int teleporterIndex)
{
    return teleporters[teleporterIndex];
}

Teleporter **Room::getTeleporters()
{
    return teleporters;
}

int Room::getItemsSize()
{
    return itemsArrayIndex;
}

int Room::getTileColor()
{
    return tileColor;
}