#include <stdio.h>
#include "linkedList.h"

int WhoisPrecede(int d1, int d2){
  if(d1 < d2){
    return 0;
  } else {
    return 1;
  }
}


int main(void){
  List list;
  int data;
  ListInit(&list);

  SetSortRule(&list, WhoisPrecede);

  LInsert(&list, 7);
  LInsert(&list, 1);
  LInsert(&list, 5);
  LInsert(&list, 22);
  LInsert(&list, 10);
  LInsert(&list, 21);

  printf("현재 데이터의 수 : %d \n", LCount(&list));

  if(LFirst(&list, &data)){
    printf("%d ", data);

    while(LNext(&list, &data)){
      printf("%d ", data);
    }
  }
  printf("\n\n");

  if(LFirst(&list, &data)){
    if(data == 22){
      LRemove(&list);
    }
    while(LNext(&list, &data)){
      if(data == 22){
        LRemove(&list);
      }
    }
  }
  printf("현재 데이터의 수 : %d \n", LCount(&list));
  if(LFirst(&list, &data)){
    printf("%d ", data);
    while (LNext(&list, &data)) {
      printf("%d ", data);
    }
  }
  printf("\n\n");
}
