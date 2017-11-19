#include <stdio.h>
#include <string.h>

typedef int bool;
#define FALSE 0
#define TRUE 1

#define BK 10
#define SL 1

int hashTable[BK][SL];

int hash(int key){
  return key % 10; //10으로 나눈 나머지를 key로 취한다.
}

void addKey(int key){
  int bucket;
  bucket = hash(key);
  if(hashTable[bucket][0] == 0){
    hashTable[bucket][0] = key;
  }
}

bool findKey(int key){
  int bucket;
  bucket = hash(key);
  return (hashTable[bucket][0] == key);
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
