/* ..............................................
  @file Aarow.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-26
  
  
.............................................. */
#include "Aarow.h"

/* ..............................................
  @brief Construct a new Aarow:: Aarow object
  
.............................................. */
Aarow::Aarow() : Object(':', "Silver", 3, 3, "Aarow")
{
  this->weight = 2;
}

/* ..............................................
  @brief Construct a new Aarow:: Aarow object
  
  @param row 
  @param col 
.............................................. */
Aarow::Aarow(int row, int col) : Object(':', "Generic", row, col, "Aarow")
{
  weight = 2;
}

/* ..............................................
  @brief Destroy the Aarow:: Aarow object
  
.............................................. */
Aarow::~Aarow()
{
}

/* ..............................................
  @brief 
  
  @param row 
  @param col 
.............................................. */
void Aarow::setPosition(int row, int col)
{
  this->setRowPos(row);
  this->setColPos(col);
}

/* ..............................................
  @brief 
  
  @return int 
.............................................. */
int Aarow::getWeight()
{
  return weight;
}

/* ..............................................
  @brief 
  
  @return string 
.............................................. */
string Aarow::getName()
{
  return name;
}

/* ..............................................
  @brief 
  
  @param w 
.............................................. */
void Aarow::setWeight(int w)
{
  weight = w;
}