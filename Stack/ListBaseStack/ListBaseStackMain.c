#include <stdio.h>
#include "ListBaseStack.h"

int main(void){
  Stack stack;
  StackInit(&stack);

  Push(&stack ,1);
  Push(&stack ,2);
  Push(&stack ,3);
  Push(&stack ,4);
  Push(&stack ,5);

  while(!isEmpty(&stack)){
    printf("%d ", Pop(&stack));
  }
}
