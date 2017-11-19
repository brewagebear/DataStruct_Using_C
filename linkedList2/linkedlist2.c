#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HSZ 127
#define HASHING(x) ((x)%HSZ)

struct node_t{
  int val;
  struct node_t *next;
};

struct node_t hash_table[HSZ];
struct node_t *head;

void init(void){
  hash_table = (struct node_t*)malloc(sizeof(struct node_t)*HSZ);
  hash_table->next = NULL;
}

void insert_hash(int value){
  int key = HASHING(value);
  struct node_t *newNode;
  newNode = (struct node_t*)malloc(sizeof(struct node_t));
  if(hash_table[key] == NULL){

  }

}
