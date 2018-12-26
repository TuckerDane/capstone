/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			09 December 2016
//
//	Description:	vHallWay
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "hHallWay.h"

/***************************************************************************************************
**	HallWay constuctor
***************************************************************************************************/
hHallWay::hHallWay()
{
	setSpSize();
}

/***************************************************************************************************
**	sets size of room
***************************************************************************************************/
void hHallWay::setSpSize()
{
	spSizeRow = 5;
	spSizeCol = 11;
}

/***************************************************************************************************
**	sets the room up
***************************************************************************************************/
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

/***************************************************************************************************
**	Sets aarow position
***************************************************************************************************/
void hHallWay::setObjectPos(Object *o)
{
	this->setSpPos(o, o->getRowPos(), o->getColPos());
}
