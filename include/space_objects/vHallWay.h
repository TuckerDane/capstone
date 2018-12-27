/* ..............................................
  @file vHallWay.h
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-27
  
  
.............................................. */

#ifndef VHALLWAY_HPP
#define VHALLWAY_HPP

#include "Space.h"

/* ..............................................
  @brief 
  
.............................................. */
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