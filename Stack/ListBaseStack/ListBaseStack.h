#ifndef __LB_STACK_H__
#define __LB_STACK_H__

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node{
  Data data;
  struct _node *next;
} Node;

typedef struct _listBaseStack {
  Node *head; //연결리스트의 머리에 데이터를 추가하는 연결리스트 = 스택으로 볼 수가 있다.
} ListStack;

typedef ListStack Stack;

void StackInit(Stack *pstack);
int isEmpty(Stack *pstack);

void Push(Stack *pstack, Data data);
Data Pop(Stack *pstack);
Data Peek(Stack *pstack);

#endif
