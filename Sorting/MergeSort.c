#include <stdio.h>
#include <stdlib.h>

int *arr;
int len;

void MergeTwoArea(int arr[], int left, int mid, int right){
  int fIdx = left;
  int rIdx = mid + 1;
  int i;

  int * sortArr = (int*)malloc(sizeof(int)*(right+1));
  int sIdx = left;
  while(fIdx <= mid && rIdx <= right){
    if(arr[fIdx] >= arr[rIdx]){
      sortArr[sIdx] = arr[fIdx++];
    } else {
      sortArr[sIdx] = arr[rIdx++];
    }
    sIdx++;
  }

  if(fIdx > mid){
    for(i = rIdx; i <= right; i++, sIdx++){
      sortArr[sIdx] = arr[i];
    }
  } else {
    for(i= fIdx; i <= mid; i++, sIdx++){
      sortArr[sIdx] = arr[i];
    }
  }
  for(i = left; i <= right; i++){
    arr[i] = sortArr[i];
  }
  free(sortArr);
}

void MergeSort(int arr[], int left, int right){
  int mid;
  if(left < right){
    mid = (left + right) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid+1, right);

    MergeTwoArea(arr, left, mid, right);
  }
}

void PrintResult(int arr[], int len){
  int i;
  for(i=0; i < len; i++){
    printf("%d\n", arr[i]);
  }
}


int main(void){
  int i;
  scanf(" %d", &len);
  arr = (int *)malloc(len*sizeof(int));

  for(i=0; i<len; i++){
    scanf(" %d", &arr[i]);
  }
  MergeSort(arr, 0, len-1);
  PrintResult(arr, len);
}
