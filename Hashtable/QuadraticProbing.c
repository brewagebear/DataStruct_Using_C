#include <stdio.h>
#include <string.h>

#define BK 10
#define SL 1

typedef int BOOL;
#define FALSE 0
#define TRUE 1

int hashTable[BK][SL];

int hash(int key){
  return key % 10;
}

int hash2(int key){
  return (key/10 + key%10) %10;
}

void addKey(int key){
  int bucket;

  bucket = hash(key);
  if(hashTable[bucket][0] != 0){
    bucket = hash2(key);
  }
  if(hashTable[bucket][0] == 0){
    hashTable[bucket][0] = key;
  }
}

BOOL findKey(int key){
  int bucket;
  bucket = hash(key);

  if(hashTable[bucket][0] == key){
    return TRUE;
  }
  bucket = hash2(key);
  if(hashTable[bucket][0] == key){
    return TRUE;
  }
  return FALSE;
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
