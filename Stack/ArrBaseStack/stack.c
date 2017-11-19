#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void StackInit(Stack *pstack){
  pstack->topIndex = -1;
}
int IsEmpty(Stack *pstack){
  if(pstack->topIndex == -1){
    return TRUE;
  } else {
    return FALSE;
  }
}

void Push(Stack *pstack, Data data){
  pstack->topIndex += 1; //push 할때마다 Top ++;
  pstack->stackArr[pstack->topIndex] = data; // 증가된 Top의 index를 갖는 array에 데이터 저장
}

Data Pop(Stack *pstack){
  int rIdx; //현재 탑을 가르키는 변수
  if(IsEmpty(pstack)){ //비었을 경우 프로그램 종료
    printf("Stack Memory Error !");
    exit(-1);
  }
  rIdx = pstack->topIndex; //현재 top을 변수에 담는다.
  pstack->topIndex -= 1; //Pop하면서 -1

  return pstack->stackArr[rIdx]; //현재 top에 있던 변수 리턴
}

Data Peek(Stack *pstack){
  if(IsEmpty(pstack)){
    printf("Stack Memory Error !");
    exit(-1);
  }
  return pstack->stackArr[pstack->topIndex];
}
