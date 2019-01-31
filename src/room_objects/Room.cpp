/* ..............................................
  @file Room.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2019-01-20
  
  
.............................................. */
#include "Room.h"

/* ..............................................
  CONSTRUCTORS/DECONSTRUCTORS 
  
.............................................. */

Room::Room()
{
    this->setWalls("rooms/generic.room");
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        this->items[i] = NULL;
    }
    for (int i = 0; i < MAX_DOORS; i++)
    {
        this->doors[i] = NULL;
    }
    this->type = "Room";
    this->name = "Generic Room";
    this->description = "A generic room";
    this->tileColor = 0;
}

Room::Room(string roomFile)
{
    this->setWalls(roomFile);
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        this->items[i] = NULL;
    }
    for (int i = 0; i < MAX_DOORS; i++)
    {
        this->doors[i] = NULL;
    }
    this->type = "Room";
    this->name = "Generic Room";
    this->description = "A generic room";
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
                this->walls[height][width] = c;
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

void Room::setItems()
{
    //TODO: setItems()
}

void Room::setItem(Item *item, int itemIndex)
{
	items[itemIndex] = item;
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

void Room::setTileColor(int tileColor)
{
    this->tileColor = COLOR_BLACK;
}

/* ..............................................
  GETTERS 
  
.............................................. */

int Room::getMaxHeight()
{
    return this->MAX_HEIGHT;
}

int Room::getMaxWidth()
{
    return this->MAX_WIDTH;
}

int Room::getMaxItems()
{
    return this->MAX_ITEMS;
}

int Room::getMaxDoors()
{
    return this->MAX_DOORS;
}

char Room::getWall(int height, int width)
{
    return this->walls[height][width];
}

Item **Room::getItems()
{
    return this->items;
}

Item *Room::getItem(int itemIndex)
{
    return items[itemIndex];
}

string Room::getType()
{
    return this->type;
}

string Room::getName()
{
    return this->name;
}

string Room::getDescription()
{
    return this->description;
}

Door *Room::getDoor(int doorIndex)
{
    return doors[doorIndex];
}

Door **Room::getDoors()
{
    return doors;
}

int Room::getTileColor()
{
    return tileColor;
}
