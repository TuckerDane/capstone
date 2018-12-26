/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			09 December 2016
//
//	Description:	Hallway
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef VHALLWAY_HPP
#define VHALLWAY_HPP

#include "Space.h"

class vHallWay : public Space
{
protected:
	Aarow a[6];

public:
	vHallWay();

	void setSpSize();
	void setSpace(string sn, Player *p, Space *l, Space *r, Space *t, Space *b, Object *o, int num);
	void setObjectPos(Object *o);
};


#endif                                 