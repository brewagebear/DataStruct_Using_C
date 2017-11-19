#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

#define TRUE 1
#define FALSE 0

typedef int Ldata;

typedef struct _node {
  Ldata data;
  struct _node * next;
} Node;

typedef struct _linkedList{
  Node *head;
  Node *cur;
  Node *before;
  int numOfdata;
  int (*comp)(Ldata d1, Ldata d2);
} LinkedList;

typedef LinkedList List;

void ListInit(List *plist);
void LInsert(List *plist, Ldata data);

int LFirst(List *plist, Ldata *pdata);
int LNext(List *plist, Ldata *pdata);

Ldata LRemove(List *plist);
int LCount(List *plist);

void SetSortRule(List *plist, int(*comp)(Ldata d1, Ldata d2));

#endif
