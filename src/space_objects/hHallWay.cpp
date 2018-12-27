/* ..............................................
  @file hHallWay.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-26
  
  
.............................................. */
#include "hHallWay.h"

/* ..............................................
  @brief Construct a new h Hall Way::h Hall Way object
  
.............................................. */
hHallWay::hHallWay()
{
	setSpSize();
}

/* ..............................................
  @brief 
  
.............................................. */
void hHallWay::setSpSize()
{
	spSizeRow = 5;
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
void hHallWay::setSpace(string sn, Player *p, Space *l, Space *r, Space *t, Space *b, Object *o, int num)
{
	spaceName = sn;
	spaceNum = num;
	spaceType = "HALLWAY";

	a[0].setPosition(1, 3);
	a[1].setPosition(1, 5);
	a[2].setPosition(1, 7);
	a[3].setPosition(3, 3);
	a[4].setPosition(3, 5);
	a[5].setPosition(3, 7);

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
void hHallWay::setObjectPos(Object *o)
{
	this->setSpPos(o, o->getRowPos(), o->getColPos());
}
