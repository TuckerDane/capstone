/* ..............................................
  @file Room.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-26
  
  
.............................................. */
#include "Room.h"

/* ..............................................
  @brief Construct a new Room:: Room object
  
.............................................. */
Room::Room()
{
	setSpSize();
}

/* ..............................................
  @brief 
  
.............................................. */
void Room::setSpSize()
{
	spSizeRow = 11;
	spSizeCol = 11;
}

/* ..............................................
  @brief 
  
  @param sn 
  @param p 
  @param l 
  @param r 
  @param t 
  @param b 
  @param o 
  @param num 
.............................................. */
void Room::setSpace(string sn, Player *p, Space *l, Space *r, Space *t, Space *b, Object *o, int num)
{
	spaceName = sn;
	spaceNum = num;
	spaceType = "SMALL ROOM";
	setObjectPos(o);
	player = p;
	setSpSize();
	setDoors(!(l == NULL), !(r == NULL), !(t == NULL), !(b == NULL));
	left = l;
	right = r;
	top = t;
	bottom = b;
}

/* ..............................................
  @brief 
  
  @param o 
.............................................. */
void Room::setObjectPos(Object *o)
{
	this->setSpPos(o, o->getRowPos(), o->getColPos());
}
