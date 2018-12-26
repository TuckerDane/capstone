/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			09 December 2016
//
//	Description:	GreatRoom
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "GreatRoom.h"

/***************************************************************************************************
**	GreatRoom constuctor
***************************************************************************************************/
GreatRoom::GreatRoom()
{
	setSpSize();
}

/***************************************************************************************************
**	sets size of room
***************************************************************************************************/
void GreatRoom::setSpSize()
{
	spSizeRow = 21;
	spSizeCol = 21;
}

/***************************************************************************************************
**	sets the room up
***************************************************************************************************/
void GreatRoom::setSpace(string sn, Player *p, Space *l, Space *r, Space *t, Space *b, Object *o, int num)
{
	spaceName = sn;
	spaceNum = num;
	spaceType = "GREATROOM";

	if (o != NULL)
	{
		if (this->getSwitch(0)->getSymbol() == 'A')						// if the switch is an aarow switch
		{
			setObjectPos(this->getSwitch(0));							// set the the switch
		}
		else
		{
			for (int i = 0; i < 5; i++)										// if it is the stone switches
			{
				setObjectPos(this->getSwitch(i));							// set all of the stone switches
			}
		}
	}

	player = p;
	setSpSize();
	setDoors(!(l == NULL), !(r == NULL), !(t == NULL), !(b == NULL));
	left = l;
	right = r;
	top = t;
	bottom = b;
}

/***************************************************************************************************
**	Sets stone position
***************************************************************************************************/
void GreatRoom::setObjectPos(Object *o)
{
	this->setSpPos(o, o->getRowPos(), o->getColPos());
}

/***************************************************************************************************
**	Sets switches
***************************************************************************************************/
void GreatRoom::setSwitches(Switch *sw, int num)
{
	for (int i = 0; i < num; i++)
	{
		s[i] = (sw + i);
	}
}

/***************************************************************************************************
**	gets switches
***************************************************************************************************/
Switch* GreatRoom::getSwitch(int i)
{
	return s[i];
}
