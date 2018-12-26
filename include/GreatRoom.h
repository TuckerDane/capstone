/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			09 December 2016
//
//	Description:	GreatRoom
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef GREATROOM_HPP
#define GREATROOM_HPP

#include "Space.h"
#include "Switch.h"

class GreatRoom : public Space
{
protected:
	Switch *s[5];

public:
	GreatRoom();

	void setSpSize();
	void setSpace(string sn, Player *p, Space *l, Space *r, Space *t, Space *b, Object *o, int num);
	void setObjectPos(Object *o);
	void setSwitches(Switch *sw, int num);

	Switch* getSwitch(int i);
};


#endif                                 