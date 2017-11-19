#ifndef __ADVANCED_HEAP_H__
#define __ADVANCED_HEAP_H__

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char HData;
//우선순위 결정 함수
typedef int PriorityComp(HData d1, HData d2);
//첫 번째 인자의 우선순위가 높다면, 0보다 큰 값이 반환되도록
//두 번째 인자의 우선순위가 높다면, 0보다 작은 값이 반환되도록
//첫 번째, 두 번째 인자의 우선순위가 동일하다면, 0이 반환되도록

typedef struct _heap{
  PriorityComp *comp;
  int numOfData;
  HData heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap *ph, PriorityComp pc);
int HisEmpty(Heap *ph);
void HInsert(Heap *ph, HData data);
HData HDelete(Heap *ph);

#endif
