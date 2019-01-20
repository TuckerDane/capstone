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
    int i = 0;
    char c;
    fstream file;
    file.open(spaceFile,fstream::in);
    if (file.is_open())
    {
        file.get(c);
        while(file.good())
        {
            this->walls[i] = c;
            i++;
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

char* Space::getWalls()
{
    return this->walls;
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