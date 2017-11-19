#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define TRUE 1
#define FALSE 0

typedef char element;

typedef struct QNode{
  element data;
  struct QNode *link;
} QNode;

typedef struct{
  QNode *front, *rear;
} LQueueType;

LQueueType *createLinkedQueue(){
  LQueueType *LQ;
  LQ = (LQueueType *)malloc(sizeof(LQueueType));
  LQ->front = NULL;
  LQ->rear = NULL;
  return LQ;
}

bool isEmpty(LQueueType *LQ){
  if(LQ->front == NULL){
    printf("\n Linked Queue is empty! \n");
    return 1;
  } else return 0;
}

void enQueue(LQueueType *LQ, element item){
  QNode *newNode = (QNode *)malloc(sizeof(QNode));
  newNode->data = item;
  newNode->link = NULL;
  if(LQ->front == NULL){
    LQ->front = newNode;
    LQ->rear = newNode;
  } else {
    LQ->rear->link = newNode;
    LQ->rear = newNode;
  }
}

element deQueue(LQueueType *LQ){
  QNode *old = LQ->front;
  element item;
  if(isEmpty(LQ)) {return 0; }
  else {
    item = old->data;
    LQ->front = LQ->front->link;
    if(LQ->front == NULL){
      LQ->rear = NULL;
      free(old);
      return item;
    }
    return 0;
  }
}

int del(LQueueType *LQ){
  QNode *old = LQ->front;
  if(isEmpty(LQ)) {return 0; }
   else {
     LQ->front = LQ->front->link;
     if(LQ->front == NULL){
       LQ->rear = NULL;
       free(old);
       return 1;
     }
  }
  return 0;
}

element peek(LQueueType *LQ){
  element item;
  if(isEmpty(LQ)) { return 0; }
  else {
      item = LQ->front->data;
      return item;
  }
}

void printLQ(LQueueType *LQ){
  QNode *temp = LQ->front;
  printf(" Linked Queue : [");
  while(temp){
    printf("%3c", temp->data);
    temp = temp->link;
  }
  printf(" ] \n");
}

int main(void){
  LQueueType *LQ1 = createLinkedQueue();
  element data;
  printf("삽입 A >>"); enQueue(LQ1, 'A'); printLQ(LQ1);
  printf("삽입 B >>"); enQueue(LQ1, 'B'); printLQ(LQ1);
  printf("삭제   >>"); deQueue(LQ1); printLQ(LQ1);
  printf("삽입 C >>"); enQueue(LQ1, 'C'); printLQ(LQ1);
  data = peek(LQ1); printf(" peek item : %c \n", data);
  printf("삽입 D >>"); enQueue(LQ1, 'D'); printLQ(LQ1);
  printf("삽입 E >>"); enQueue(LQ1, 'E'); printLQ(LQ1);
  return 0;
}
