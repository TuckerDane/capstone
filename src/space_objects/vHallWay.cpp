/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			09 December 2016
//
//	Description:	vHallWay
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "vHallWay.h"

/***************************************************************************************************
**	HallWay constuctor
***************************************************************************************************/
vHallWay::vHallWay()
{
	setSpSize();
}

/***************************************************************************************************
**	sets size of room
***************************************************************************************************/
void vHallWay::setSpSize()
{
		spSizeRow = 11;
		spSizeCol = 5;
}

/***************************************************************************************************
**	sets the room up
***************************************************************************************************/
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

/***************************************************************************************************
**	Sets aarow position
***************************************************************************************************/
void vHallWay::setObjectPos(Object *o)
{
	this->setSpPos(o, o->getRowPos(), o->getColPos());
}
