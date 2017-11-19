#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define TRUE 1
#define FALSE 0


typedef char element;
typedef struct DQNode{
  element data;
  struct DQNode *llink;
  struct DQNode *rlink;
} DQNode;

typedef struct {
  DQNode *front, *rear;
} DQueType;

DQueType *createDQue(){
  DQueType *DQ;
  DQ = (DQueType *)malloc(sizeof(DQueType));
  DQ->front = NULL;
  DQ->rear = NULL;
  return DQ;
}

bool isEmpty(DQueType *DQ){
  if(DQ->front == NULL || DQ->rear == NULL){
    printf("\n Linked QUeue is empty! \n");
    return TRUE;
  } else {
    return FALSE;
  }
}
//앞에서 삽입
void insertFront(DQueType *DQ, element item){
  DQNode *newNode = (DQNode *)malloc(sizeof(DQNode));
  newNode->data = item;
  if(DQ->front == NULL){
    DQ->front = newNode;
    DQ->rear = newNode;
    newNode->rlink = NULL;
    newNode->llink = NULL;
  } else {
    DQ->front->llink = newNode; //왼쪽링크에 새 링크를 연결
    newNode->rlink = DQ->front; //이전노드를 오른쪽 링크에 붙임
    newNode->llink = NULL; //새로운 노드의 왼쪽링크 초기화
    DQ->front = newNode; //맨 앞자리에 새 노드 연결
  }
}

//뒤에서 삽입
void insertRear(DQueType *DQ, element item){
  DQNode *newNode = (DQNode *)malloc(sizeof(DQNode));
  newNode->data = item;
  if(DQ->rear == NULL){
    DQ->front = newNode;
    DQ->rear = newNode;
    newNode->rlink = NULL;
    newNode->llink = NULL;
  } else {
    DQ->rear->rlink = newNode; //리어의 오른쪽 링크에 새 노드 삽입
    newNode->rlink = NULL; //새로운 노드의 오른쪽 링크 초기화
    newNode->llink = DQ->rear; //새로운 노드에 왼쪽링크에 이전노드 연결
    DQ->rear = newNode; //새로운 노드를 최신화
  }
}

element deleteFront(DQueType *DQ){
  DQNode *old = DQ->front;
  element item;
  if(isEmpty(DQ)) return 0;
  else {
    item = old->data;
    if(DQ->front->rlink == NULL){ //덱이 비어있을 경우
      DQ->front = NULL;
      DQ->rear = NULL;
    } else {
      DQ->front = DQ->front->rlink; //DQ->front에 다음 노드를 삽입
      DQ->front->llink = NULL; // 왼쪽 리크 초기화
    }
    free(old); // 현재 노드 삭제
    return item;
  }
}

element deleteRear(DQueType *DQ){
  DQNode *old = DQ->rear;
  element item;
  if(isEmpty(DQ)) return 0;
  else {
    item = old->data;
    if(DQ->rear->llink == NULL){ //덱이 빈 경우
      DQ->front = NULL;
      DQ->rear = NULL;
    } else {
      DQ->rear = DQ->rear->llink; //현재 노드의 다음 노드를 현재노드에 대입 (자리교환)
      DQ->rear->rlink = NULL; //오른쪽 링크를 초기화
    }
    free(old);
    return item;
  }
}

bool removeFront(DQueType *DQ){
  DQNode *old = DQ->front;
  if(isEmpty(DQ)) return FALSE;
  else {
    if(DQ->front->rlink == NULL){ //덱이 비어있을 경우
      DQ->front = NULL;
      DQ->rear = NULL;
    } else {
      DQ->front = DQ->front->rlink; //DQ->front에 다음 노드를 삽입
      DQ->front->llink = NULL; // 왼쪽 리크 초기화
    }
    free(old); // 현재 노드 삭제
     return TRUE;
  }
}

bool removeRear(DQueType *DQ){
  DQNode *old = DQ->rear;
  if(isEmpty(DQ)) return FALSE;
  else {
    if(DQ->rear->llink == NULL){ //덱이 빈 경우
      DQ->front = NULL;
      DQ->rear = NULL;
    } else {
      DQ->rear = DQ->rear->llink; //현재 노드의 다음 노드를 현재노드에 대입 (자리교환)
      DQ->rear->rlink = NULL; //오른쪽 링크를 초기화
    }
    free(old);
    return TRUE;
  }
}

element peekFront(DQueType *DQ){
  element item;
  if(isEmpty(DQ)){
    return 0;
  } else {
    return item = DQ->front->data;
  }
}

element peekRear(DQueType *DQ){
  element item;
  if(isEmpty(DQ)){
    return 0;
  } else {
    return item = DQ->rear->data;
  }
}

void printDQ(DQueType *DQ){
  DQNode *temp = DQ->front;
  printf("DeQue : [ ");
  while(temp){
    printf("%3c", temp->data);
    temp = temp->rlink;
  }
  printf(" ] \n");
}

int main(void){
  DQueType *DQ1 = createDQue();
  element data;
  printf("front 삽입 A >> "); insertFront(DQ1, 'A'); printDQ(DQ1);
  printf("front 삽입 B >> "); insertFront(DQ1, 'B'); printDQ(DQ1);
  printf("rear  삽입 C >> "); insertRear(DQ1, 'C'); printDQ(DQ1);
  printf("front 삭제  >> "); deleteFront(DQ1); printDQ(DQ1);
  printf("rear  삭제  >> "); deleteRear(DQ1); printDQ(DQ1);
  printf("front 삭제  >> "); deleteFront(DQ1); printDQ(DQ1);
  printf("rear  삽입 D >> "); insertRear(DQ1, 'D'); printDQ(DQ1);
  printf("front 삽입 E >> "); insertFront(DQ1, 'E'); printDQ(DQ1);
  printf("front 삽입 F >> "); insertFront(DQ1, 'F'); printDQ(DQ1);

  data = peekFront(DQ1); printf("peek Front item : %c \n", data);
  data = peekRear(DQ1); printf("peek Front item : %c \n", data);
}
