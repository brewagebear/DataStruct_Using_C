#include <stdio.h>
#include "ArrayList.h"

void ListInit(List * plist){
  (plist->numOfData) = 0;
  (plist->curPosition) = -1;
}
void LInsert(List * plist, LData data){
  if(plist->numOfData >= LIST_LEN){
    puts("저장이 불가능합니다.");
    return;
  }
  plist->arr[plist->numOfData] = data; //포인터로 전달된 list의 멤버인 arr에 numOfData (데이터의 개수값 인덱스를 받고, 데이터 저장
  (plist->numOfData)++;
}

int LFirst(List * plist, LData * pdata){
  if(plist->numOfData == 0){
    return FALSE;
  }
  (plist->curPosition) = 0; //참조위치 초기화
  *pdata = plist->arr[0]; //pdata가 가리키는 공간에 저장
  return TRUE;
}

int LNext(List * plist, LData * pdata){
  if(plist->curPosition >= (plist->numOfData)-1){
    return FALSE;
  }
  (plist->curPosition)++;
  *pdata = plist->arr[plist->curPosition];
  return TRUE;
}

LData LRemove(List * plist){
  int rpos = plist->curPosition;
  int num = plist->numOfData;
  int i;

  LData rdata = plist->arr[rpos]; //인자로 전달받은 값의 참조위치의 데이터를 가져온다.

  for(i=rpos; i<num-1; i++){
    plist->arr[i] = plist->arr[i+1];
  }
    (plist->numOfData)--;
    (plist->curPosition)--;
    return rdata;
}
int LCount(List * plist){
  return plist->numOfData;
};
