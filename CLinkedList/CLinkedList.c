#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

#define HEAD plist->tail->next

void ListInit(List *plist){
  plist->tail = NULL;
  plist->cur = NULL;
  plist->before = NULL;
  plist->numOfdata = 0;
}

void LInsertFront(List *plist, Data data){
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;

  if(plist->tail == NULL){
    plist->tail = newNode;
    newNode->next = newNode;
  } else {
    newNode->next = HEAD; //새로운 노드의 다음값은 기존 꼬리가 들고 있던거 +1
    HEAD = newNode; // 테일은 다시 새로운 노드를 가르키게 한다.
  }
  (plist->numOfdata)++;
}

void LInsert(List *plist, Data data){ //꼬리에 노드 추가
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  if(plist->tail == NULL){
    plist->tail = newNode;
    newNode->next = newNode;
  } else {
    newNode->next = HEAD;
    HEAD = newNode;
    plist->tail = newNode; //LInsertFront와 유일한 차이점
  }
  (plist->numOfdata)++;
}

int LFirst(List *plist, Data *pdata){
  if(plist->tail == NULL){
    return FALSE;
  }

  plist->before = plist->tail;
  plist->cur = plist->tail->next;

  *pdata = plist->cur->data;
  return TRUE;
}

int LNext(List *plist, Data *pdata){
  if(plist->tail == NULL){
    return FALSE;
  }
  plist->before = plist->cur; // before가 다음 노드를 가르키게 한다.
  plist->cur = plist->cur->next; // cur이 다음 노드를 가르키게한다.

  *pdata = plist->cur->data; // cur이 가르키는 노드의 데이터 반환
  return TRUE;
}

Data LRemove(List *plist){
  Node *rpos = plist->cur;
  Data rdata = rpos->data;

  if(rpos == plist->tail){
    if(plist->tail == plist->tail->next){ //즉, 삭제할 데이터 하나만 리스트에 남을 경우
      plist->tail = NULL; // 꼬리는 널을 가르킨다.
    } else {
      plist->tail = plist->before;
    }
  }
  plist->before->next = plist->cur->next;
  plist->cur = plist->before;

  free(rpos);
  (plist->numOfdata)--;
  return rdata;
}

int LCount(List *plist){
  return plist->numOfdata;
}
