/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			09 December 2016
//
//	Description:	GreatRoom
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef ROOM_HPP
#define ROOM_HPP

#include "Space.h"

class Room : public Space
{
protected:
	Stone *s;

public:
	Room();

	void setSpSize();
	void setSpace(string sn, Player *p, Space *l, Space *r, Space *t, Space *b, Object *o, int num);
	void setObjectPos(Object *o);
};


#endif                                 