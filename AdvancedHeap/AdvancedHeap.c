#include "AdvancedHeap.h"

void HeapInit(Heap *ph, PriorityComp pc){
  ph->numOfData = 0;
  ph->comp = pc;
}

int HisEmpty(Heap *ph){
  if(ph->numOfData == 0){
    return TRUE;
  } else {
    return FALSE;
  }
}

int GetParentIDX(int idx){
  return idx/2;
}

int GetLchildIDX(int idx){
  return idx*2;
}

int GetRchildIDX(int idx){
  return GetLchildIDX(idx)+1;
}

int GetHiPriChildIDX(Heap *ph, int idx){ // 노드의 인덱스 값을 전달하면 두 자식 노드중에서 우선순위 높은 것의 인덱스값 반환
  //자식 노드 X
  if(GetLchildIDX(idx) > ph->numOfData){
    return 0;
  //왼쪽 자식 노드 하나만 존재 (힙은 완전이진트리이므로 하나뿐인 자식노드는 왼쪽 자식 노드이며, 힙의 마지막 노드이다.)
  } else if(GetLchildIDX(idx) == ph->numOfData){
    return GetLchildIDX(idx);
  //자식 노드가 둘 다 존재
  } else {
    //오른쪽 자식의 우선순위가 높을 경우
    //if(ph->heapArr[GetLchildIDX(idx)].pr > ph->heapArr[GetRchildIDX(idx)].pr){
    if(ph->comp(ph->heapArr[GetLchildIDX(idx)], ph->heapArr[GetRchildIDX(idx)]) < 0 ){
      return GetRchildIDX(idx);
    } else {
      return GetLchildIDX(idx);
    }
  }
}
//힙의 삽입연산
/*
 새로운 데이터는 우선순위가 가장 낮다는 가정하에 '마지막 위치'에 저장
 그리고 우선순우의 비교를 통해서 자신의 위치를 찾을때까지 위로 올린다.
*/
void HInsert(Heap *ph, HData data){
  int idx = ph->numOfData+1; // 새 노드가 저장될 인덱스값

  //새 노드가 저장될 위치가 1(즉, 루트노드)가 아니라면 반복문 실행
  while (idx != 1){
    //계속해서 비교한다, 부모노드와 새노드의 우선순위를
    // if(pr < ph->heapArr[GetParentIDX(idx)].pr){ // 새 노드의 우선순위가 높다면
    if(ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0){
      ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)]; // 부모 노드를 한 레벨 내림
      idx = GetParentIDX(idx); // 새 노드를 한 레벨 올림
    } else {
      break;
    }
  }
  ph->heapArr[idx] = data;
  ph->numOfData += 1;
}
//힙의 삭제연산
/*
  힙의 마지막 노드를 루트 노드의 위치에 올리고, 자식 노드와의 비교과정을 거치면서 아래로 내린다 (자신의 위치를 찾을때까지)
  논리적으로는 이렇지만 사실 구현할때는 임시 저장소에서 넣어놓고, 목적지가 결정되면 단번에 바로 교체하면 된다.
*/
HData HDelete(Heap *ph){
  HData retData = ph->heapArr[1];
  HData lastElem = ph->heapArr[ph->numOfData];

  int parentIdx = 1; // 루트 노드가 위치해야할 인덱스 값 저장
  int childidx;
  //루트 노드의 우선순위가 높은 자식 노드를 시작으로 반복문 시작
  while(childidx = GetHiPriChildIDX(ph, parentIdx)){
    //if(lastElem.pr <= ph->heapArr[childidx].pr){ //마지막 노드와 우선순위 비교
    if(ph->comp(lastElem, ph->heapArr[childidx]) >= 0){
      break; // 마지막 노드의 우선순위가 높으면 반복문 탈출
    }
    //마지막 노드보다 우선순위가 높으니, 비교대상 노드를 위치를 한 레벨 올림
    ph->heapArr[parentIdx] = ph->heapArr[childidx];
    parentIdx = childidx; // 마지막 노드가 저장될 위치정보를 한 레벨 내림
  }
  ph->heapArr[parentIdx] = lastElem; // 마지막 노드 최종 저장
  ph->numOfData -= 1;
  return retData;
}
