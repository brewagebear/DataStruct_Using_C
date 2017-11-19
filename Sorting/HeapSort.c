#include <stdio.h>
#include <stdlib.h>

#define LEFT_CHILD(index) 2 * index + 1
#define RIGHT_CHILD(index) 2 * index + 2

int *arr;
int LENGTH;
int heapSize;

//힙 구성 연산
void Heapify(int arr[], int LENGTH){
  int largest;
  int left = LEFT_CHILD(LENGTH);
  int right = RIGHT_CHILD(LENGTH);
  if(left <= heapSize && arr[left] > arr[LENGTH]) //맨 마지막 노드가 가장 우선순위가 높을경우
    largest = left;
  else
    largest = LENGTH; //그게 아니라면 루트가 맥스
  if(right <= heapSize && arr[right] > arr[largest]) //오른쪽 자식 노드가 가장 우선순위가 높을 경우
    largest = right; //
  if(largest != LENGTH){ //루트가 맥스힙이 아니라면
      int temp = arr[LENGTH];
      arr[LENGTH] = arr[largest];
      arr[largest] = temp;
      Heapify(arr, largest);
    }
}

//힙을 만든다
void BuildHeap(int arr[]){
  heapSize = LENGTH-1;
  int i;
  for(i = heapSize / 2; i >= 0; i--)
    Heapify(arr, i);
}

void HeapSort(int arr[]){
  BuildHeap(arr); // 힙을 만든다
  int i;
  for(i = heapSize; i > 0; i--){
      int temp = arr[heapSize];
      arr[heapSize] = arr[0];
      arr[0] = temp;
      heapSize--;
      Heapify(arr, 0); // 재귀적으로 계속 정렬한다.
    }
}

void printfResult(int arr[]){
  int i;
  for(i=0; i<LENGTH; i++){
    printf("%d\n", arr[i]);
  }
}

int main(void) {
  int i;
  scanf(" %d", &LENGTH);
  arr = (int *)malloc(LENGTH*sizeof(int));

  for(i=0; i<LENGTH; i++){
    scanf(" %d", &arr[i]);
  }
  HeapSort(arr);
  printfResult(arr);
}
