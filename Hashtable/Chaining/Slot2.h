
#ifndef __SLOT2_H__
#define __SLOT2_H__
#include "Person.h"

typedef int Key;
typedef Person *Value;
typedef Slot *Data;

typedef struct _node{
  Data data;
  struct _node *next;
} Node;

typedef struct _slot{
  Key key;
  Value val;
} Slot;

#endif
