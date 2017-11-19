#include <stdio.h>
#include <stdlib.h>

int len;
int *arr;

void BubbleSort(int arr[], int len){
  int i, j, temp;
  for(i=0; i<len; i++){
    for(j=0; j<len - 1; j++){
      if(arr[j] > arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

void PrintResult(int arr[], int len){
  int i;
  for(i=0; i<len; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(void){
  int i;
  scanf(" %d", &len);

  arr = (int *)malloc(len*sizeof(int));
  printf("정수를 입력해주세요 : ");
  for(i=0; i<len; i++){
    scanf(" %d", &arr[i]);
  }
  BubbleSort(arr, len);
  PrintResult(arr, len);
}
