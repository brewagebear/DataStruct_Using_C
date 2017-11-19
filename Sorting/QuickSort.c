#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>

int *arr;
int len;

void swap(int arr[], int lIdx, int rIdx){
  int temp = arr[lIdx];
  arr[lIdx] = arr[rIdx];
  arr[rIdx] = temp;
}

int Partition(int arr[], int left, int right){
  int pivot = arr[left];
  int low = left+1;
  int high = right;

  while(low <= high){
    while(pivot > arr[low] && low <= right)
    low++;

    while(pivot < arr[high] && high >= (left)+1)
    high--;

    if(low <= high){
      swap(arr, low, high);
    }
  }

  swap(arr, left, high);
  return high;
}

void QuickSort(int arr[], int left, int right){
  if(left <= right){
  int pivot = Partition(arr, left, right);
  QuickSort(arr, left, pivot-1);
  QuickSort(arr, pivot+1, right);
  }
}

void PrintResult(int arr[], int len){
  int i;
  for(i=0; i < len; i++){
    printf("%d ", arr[i]);
  }
}

int main(void){
  int i;
  scanf(" %d", &len);
  arr = (int *)malloc(len*sizeof(int));

  for(i = 0; i < len; i++){
    scanf(" %d", &arr[i]);
  }

  QuickSort(arr, 0, len-1);
  PrintResult(arr, len);
}
