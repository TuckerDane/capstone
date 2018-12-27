/* ..............................................
  @file Room.h
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-27
  
  
.............................................. */

#ifndef ROOM_HPP
#define ROOM_HPP

#include "Space.h"

/* ..............................................
  @brief 
  
.............................................. */
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