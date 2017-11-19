#include <stdio.h>
#include "ListBaseQueue.h"

int main(void){
  Queue q;
  queueInit(&q);

  Enqueue(&q, 1);
  Enqueue(&q, 2);
  Enqueue(&q, 3);
  Enqueue(&q, 4);
  Enqueue(&q, 5);

  while(!isEmpty(&q)){
    printf("%d ", Dequeue(&q));
  }
}
