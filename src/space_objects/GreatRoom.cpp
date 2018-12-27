/* ..............................................
  @file GreatRoom.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-26
  
  
.............................................. */
#include "GreatRoom.h"

/* ..............................................
  @brief Construct a new Great Room:: Great Room object
  
.............................................. */
GreatRoom::GreatRoom()
{
	setSpSize();
}

/* ..............................................
  @brief 
  
.............................................. */
void GreatRoom::setSpSize()
{
	spSizeRow = 21;
	spSizeCol = 21;
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

/* ..............................................
  @brief 
  
  @param o 
.............................................. */
void GreatRoom::setObjectPos(Object *o)
{
	this->setSpPos(o, o->getRowPos(), o->getColPos());
}

/* ..............................................
  @brief 
  
  @param sw 
  @param num 
.............................................. */
void GreatRoom::setSwitches(Switch *sw, int num)
{
	for (int i = 0; i < num; i++)
	{
		s[i] = (sw + i);
	}
}

/* ..............................................
  @brief 
  
  @param i 
  @return Switch* 
.............................................. */
Switch* GreatRoom::getSwitch(int i)
{
	return s[i];
}
