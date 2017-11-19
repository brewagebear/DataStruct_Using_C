#ifndef __SLOT_H__
#define __SLOT_H__

#include "Person.h"

typedef int Key;
typedef Person *Value;

enum SlotStatus {EMPTY, DELETED, INUSE}; //현재 슬롯상태를 확인하는 키워드

typedef struct _slot{
  Key key;
  Value val;
  enum SlotStatus status;
} Slot;


#endif
