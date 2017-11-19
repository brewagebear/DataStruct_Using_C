#include <stdio.h>

typedef int bool;
#define FALSE 0
#define TRUE 1

#define BK 10
#define SL 3
int hashTable[BK][SL];

int hash(int key){
  return key % 10;
}

void addKey(int key){
  int i, bucket;

  bucket = hash(key);
  for(i=0; i<SL; i++){
    if(hashTable[bucket][i] == 0){
      hashTable[bucket][i] = key;
      break;
    }
  }
}

bool findKey(int key){
  int i, bucket;
  bucket = hash(key);
  for(i=0; i<SL; i++){
    if(hashTable[bucket][i] == key){
      return TRUE;
    } else {
    return FALSE;
    }
  }
}

int main(void) {
  int i, key;

  memset(hashTable, 0, sizeof(hashTable));
  for(i=0; i<5; i++){
    printf("%d 번째값을 입력하세요 : ", i+1);
    scanf(" %d", &key);
    addKey(key);
  }

  printf("검색할 키를 입력하세요 : ");
  scanf(" %d", &key);
  if(findKey(key)){
    puts("검색 되었습니다.");
  } else {
    puts("입력하신 값은 존재하지 않습니다.");
  }

}
