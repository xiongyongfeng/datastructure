#include<stdio.h>
#include"stack.h"

int main()
{
  stack stk;
  stack_init(&stk);
  printf("stack size = %d\n",stack_size(&stk));
  printf("stack empty = %d\n", stack_empty(&stk));

  for(int i =0; i<3;i++){
    stack_push(&stk, i*2);
    printf("stack size = %d\n",stack_size(&stk));
  }
  for(int i =0; i<3;i++){
    int rtval;
    stack_pop(&stk, &rtval);
    printf("stack size = %d\n",stack_size(&stk));
    printf("stack last value = %d\n",rtval);
  }

  return 0;

}
