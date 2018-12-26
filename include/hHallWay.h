/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Name:			Tucker Dane Walker
//
//	Date:			09 December 2016
//
//	Description:	hHallway
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef HHALLWAY_HPP
#define HHALLWAY_HPP

#include "Space.h"

class hHallWay : public Space
{
protected:
	Aarow a[6];

public:
	hHallWay();

	void setSpSize();
	void setSpace(string sn, Player *p, Space *l, Space *r, Space *t, Space *b, Object *o, int num);
	void setObjectPos(Object *o);
};


#endif                                 