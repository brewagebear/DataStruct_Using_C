#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;

struct stackNode{
  element data;
  struct stackNode *link;
} stackNode;

struct stackNode *top;

void push(element item){
  struct stackNode *temp = (struct stackNode *)malloc(sizeof(stackNode));
  temp->data = item;
  temp->link = top;
  top = temp;
}

element pop(){
  element item;
  struct stackNode *temp = top;

  if(top == NULL){
    printf("\n\n Stack is empty !\n");
    return 0;
  } else {
    item = temp->data;
    top = temp->link;
    free(temp);
    return item;
  }
}

element peek(){
  element item;
  if(top == NULL){
    printf("\n\n Stack is empty !\n");
    return 0;
  } else {
    item = top->data;
    return item;
  }
}

void del(){
  struct stackNode *temp;
  if(top == NULL){
    printf("\n\n Stack is empty !\n");
  } else {
    temp = top;
    top = top->link;
    free(temp);
  }
}

void printStack(){
  struct stackNode *p = top;
  printf("\n STACK [");
  while(p){
    printf("%d ", p->data);
    p = p->link;
  }
  printf("] ");
}

int main(void){
  element item;
  top = NULL;
  printStack();
  push(1);
  printStack();
  push(2);
  printStack();
  push(3);
  printStack();

  item = peek();
  printStack();
  printf("peek top => %d", item);
  del();
  printStack();

  item = pop();
  printStack();
  printf("peek top => %d", item);

  item = pop();
  printStack();
  printf("peek top => %d", item);

  pop();
  getchar();
  return 0;
}
