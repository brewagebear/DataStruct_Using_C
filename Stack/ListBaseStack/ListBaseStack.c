#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack *pstack){
  pstack->head = NULL;
}

int isEmpty(Stack *pstack){
  if(pstack->head == NULL){
    return TRUE;
  }
  return FALSE;
}

void Push(Stack *pstack, Data data){
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = pstack->head;

  pstack->head = newNode;
}

Data Pop(Stack *pstack){
  Data rdata;
  Node *rnode;

  if(isEmpty(pstack)){
    printf("Stack Memory Error!");
    exit(-1);
  }
  rdata = pstack->head->data; // 삭제할 노드의 데이터 저장
  rnode = pstack->head; // 삭제할 노드의 주소값 저장

  pstack->head = pstack->head->next; //삭제할 노드의 다음노드를 가르킨다.
  free(rnode);
  return rdata;
}

Data Peek(Stack *pstack){
  if(isEmpty(pstack)){
    printf("Stack Memory Error!");
    exit(-1);
  }
  return pstack->head->data;
}
