#include <stdio.h>
#include <stdlib.h>

int len;
int *arr;

void SelectionSort(int arr[], int len){
  int i, j, max, temp;
  for(i=0; i<len-1; i++){
    max = i;
    for(j=i+1; j<len; j++){
      if(arr[j] < arr[max]){
          max = j;
      }
    }
    temp = arr[i];
    arr[i] = arr[max];
    arr[max] = temp;
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
  SelectionSort(arr, len);
  PrintResult(arr, len);
}
