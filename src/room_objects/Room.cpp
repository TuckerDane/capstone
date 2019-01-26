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
    this->type = "Generic";
    this->name = "Generic Room";
    this->description = "A generic room";
}

Room::~Room()
{
    
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
    file.open(roomFile,fstream::in);
    if (file.is_open())
    {
        file.get(c);
        while(file.good())
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

void Room::setItem()
{
    //TODO: setItem()
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

char Room::getWall(int height, int width)
{
    return this->walls[height][width];
}

Item** Room::getItems()
{
    return this->items;
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