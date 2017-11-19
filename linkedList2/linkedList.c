#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

void ListInit(List *plist){
  plist->head = (Node*)malloc(sizeof(Node));
  plist->head->next = NULL;
  plist->comp = NULL;
  plist->numOfdata = 0;
}

void FInsert(List *plist, Ldata data){
  Node * newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;

  newNode->next = plist->head->next; //새 노드가 다른 노드를 가르키게함
  plist->head->next = newNode; //더미노드가 새 노드를 가르키게함
  (plist->numOfdata)++; //노드 수를 하나 증가시킴
}

void SInsert(List *plist, Ldata data){
  Node *newNode = (Node*)malloc(sizeof(Node));
  Node *pred = plist->head; //pred는 더미노드를 가르킴
  newNode->data = data; //새노드에 데이터 저장
  /*
    반복문 분석
    조건 1. 마지막 노드인가? 조건 2. 새 데이터와 pred다음 노드에 저장된 데이터의 우선순위 비교를 위한 함수호출
    따라서 반복문은 pred가 마지막 노드를 가르키는 것도 아니고, 새 데이터가 들어갈 자리도 아직 찾디 못했다면 pred를 다음 노드로 이동시키는 것!
  */
  while(pred->next != NULL && plist->comp(data, pred->next->data) != 0){
    pred = pred->next; // 다음 노드로 이동
  }
  newNode->next = pred->next; // 새 노드의 오른쪽을 연결
  pred->next = newNode; // 새 노드의 왼쪽을 연결

  (plist->numOfdata)++;
}

void LInsert(List *plist, Ldata data){
  if(plist->comp == NULL){
    FInsert(plist, data);
  } else {
    SInsert(plist, data);
  }
}

int LFirst(List *plist, Ldata *pdata){
  if(plist->head->next == NULL){ //더미노드가 NULL을 가르킨다면
    return FALSE; //반환할 데이터 X
  }
  plist->before = plist->head; // before는 더미노드를 가르키게함
  plist->cur = plist->head->next; // cur은 첫번째 노드를 가르키게함

  *pdata = plist->cur->data; //첫 번째 노드의 데이터 전달
  return TRUE; //반환 성공
}

int LNext(List *plist, Ldata *pdata){
  if(plist->cur->next == NULL){
    return FALSE;
  }
  plist->before = plist->cur; //cur이 가르키던것을 before가 가르킴
  plist->cur = plist->cur->next; //cur은 그 다음 노드를 가르킴

  *pdata = plist->cur->data; //그 데이터를 반환
  return TRUE;
}

Ldata LRemove(List *plist){
  Node *rpos = plist->cur; //소멸 대상의 주소값을 rpos에 저장
  Ldata rdata = rpos->data; //소멸 대상의 데이터를 rdata에 저장

  plist->before->next = plist->cur->next; //before가 cur의 다음노드를 가르키면서 현재 노드는 링크끊기게됌
  plist->cur = plist->before; //cur이 before를 가르키게함
  free(rpos); //삭제
  (plist->numOfdata)--; //노드 수 감소
  return rdata;
}

int LCount(List *plist){
  return plist->numOfdata;
}
// 두개의 인자를 전달받도록 함수를 정의, 첫번째의 인자의 정렬 우선순위가 높으면 0 아니면 1 이 함수를 제어할 트리거는 메인에 작성
void SetSortRule(List *plist, int (*comp)(Ldata d1, Ldata d2)){
  plist->comp = comp;
}
