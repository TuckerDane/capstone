/*....................................
  @file CubeParts.cpp
  @brief
  @date 3/9/19
.................................... */

#include "CubeParts.hpp"

/* ..............................................
  CONSTRUCTORS / DESTRUCTORS
  
.............................................. */

CubeParts::CubeParts()
{
  weight = 1;
  color = COLOR_CYAN;
  symbol = "¬";
  type = "cubepart";
  name = "Cube piece";
  description = "Cube piece";
}
CubeParts::CubeParts(int yPos, int xPos)
{
  weight = 1;
  this->xPos = xPos;
  this->yPos = yPos;
  color = COLOR_CYAN;
  symbol = "¬";
  type = "cubepart";
  name = "Cube piece";
  description = "A piece of the Cube system. If only you had all of it.";
}
CubeParts::~CubeParts()
{
	
}
