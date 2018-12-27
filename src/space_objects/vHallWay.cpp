/* ..............................................
  @file vHallWay.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-26
  
  
.............................................. */
#include "vHallWay.h"

/* ..............................................
  @brief Construct a new v Hall Way::v Hall Way object
  
.............................................. */
vHallWay::vHallWay()
{
	setSpSize();
}

/* ..............................................
  @brief 
  
.............................................. */
void vHallWay::setSpSize()
{
	spSizeRow = 11;
	spSizeCol = 5;
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
void vHallWay::setSpace(string sn, Player *p, Space *l, Space *r, Space *t, Space *b, Object *o, int num)
{
	spaceName = sn;
	spaceNum = num;
	spaceType = "HALLWAY";

	a[0].setPosition(3, 1);
	a[1].setPosition(5, 1);
	a[2].setPosition(7, 1);
	a[3].setPosition(3, 3);
	a[4].setPosition(5, 3);
	a[5].setPosition(7, 3);

	setObjectPos(&a[0]);
	setObjectPos(&a[1]);
	setObjectPos(&a[2]);
	setObjectPos(&a[3]);
	setObjectPos(&a[4]);
	setObjectPos(&a[5]);

	setDoors(!(l == NULL), !(r == NULL), !(t == NULL), !(b == NULL));

	player = p;
	setSpSize();
	left = l;
	right = r;
	top = t;
	bottom = b;
}

/* ..............................................
  @brief 
  
  @param o 
.............................................. */
void vHallWay::setObjectPos(Object *o)
{
	this->setSpPos(o, o->getRowPos(), o->getColPos());
}
