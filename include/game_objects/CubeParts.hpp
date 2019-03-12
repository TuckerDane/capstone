/*....................................
  @file CubeParts.hpp
  @brief
  @date 3/9/19
.................................... */

#ifndef CUBEPARTS_HPP
#define CUBEPARTS_HPP

#include "Item.hpp"

/* ..............................................
  @brief 
  
.............................................. */

class CubeParts : public Item
{
private:
  
public:
  CubeParts();
  CubeParts(int yPos, int xPos);
  ~CubeParts();
};

#endif