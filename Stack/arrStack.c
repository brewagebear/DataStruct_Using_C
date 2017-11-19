#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100
typedef int bool;
#define TRUE 1
#define FALSE 0

int Stack[STACK_SIZE];
int Top = -1;

void init();
void Push(int item);
bool isEmpty(int arr[]);
int Pop();
int Peek();

int main(void){
  init();
  Push(1);
  Push(2);
  Push(3);
  Push(4);
  Push(5);
  printf("%d\n", Pop());
  printf("%d\n", Pop());
  printf("%d\n", Pop());
  printf("%d\n", Pop());
  printf("%d\n", Peek());
}

void init(){
  memset(Stack, 0, sizeof(STACK_SIZE));
}

bool isEmpty(int arr[]){
  if(Top == -1){
    return TRUE;
  } else {
    return FALSE;
  }
}

void Push(int item){
  if(Top >= STACK_SIZE-1){
    printf("STACK OVER FLOW!!");
    return;
  }
  else Stack[++Top] = item;
}

int Pop(){
  if(isEmpty(Stack)){
    printf("STACK IS EMPTY");
    return 0;
  } else return Stack[Top--];
}

int Peek(){
  if(isEmpty(Stack)){
    printf("STACK IS EMPTY");
    return 0;
  } else return Stack[Top];
}
