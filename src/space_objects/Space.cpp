/* ..............................................
  @file Space.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2019-01-20
  
  
.............................................. */
#include "Space.h"

/* ..............................................
  CONSTRUCTORS/DECONSTRUCTORS 
  
.............................................. */

Space::Space()
{
    this->setWalls("spaces/generic.space");
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        this->items[i] = NULL;
    }
    this->type = "Generic";
    this->name = "Generic Space";
    this->description = "A generic space";
}

Space::~Space()
{
    
}

/* ..............................................
  SETTERS 
  
.............................................. */

void Space::setWalls(string spaceFile)
{
    int width = 0;
    int height = 0;
    char c;
    fstream file;
    file.open(spaceFile,fstream::in);
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

void Space::setItems()
{
    //TODO: setItems()
}

void Space::setItem()
{
    //TODO: setItem()
}

void Space::setType(string type)
{
    this->type = type;
}

void Space::setName(string name)
{
    this->name = name;
}

void Space::setDescription(string description)
{
    this->description = description;
}

/* ..............................................
  GETTERS 
  
.............................................. */

int Space::getMaxHeight()
{
    return this->MAX_HEIGHT;
}

int Space::getMaxWidth()
{
    return this->MAX_WIDTH;
}

int Space::getMaxItems()
{
    return this->MAX_ITEMS;
}

char Space::getWall(int height, int width)
{
    return this->walls[height][width];
}

Item** Space::getItems()
{
    return this->items;
}

string Space::getType()
{
    return this->type;
}

string Space::getName()
{
    return this->name;
}

string Space::getDescription()
{
    return this->description;
}