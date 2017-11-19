#ifndef __TABLE2_H__
#define __TABLE2_H__
#include "Slot2.h"
#include "DLinkedList.h"

#define MAX_TBL 100

typedef int HashFunc(Key k);
typedef struct _table{
  List tbl[MAX_TBL];
  HashFunc *hf;
} Table;

void TBLInit(Table *pt, HashFunc *f);
void TBLInsert(Table *pt, Key k, Value v);
void TBLDelete(Table *pt, Key k);
void TBLSearch(Table *pt, Key k);

#endif
