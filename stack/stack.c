#include"stack.h"

void stack_init(stack* p_stack){
  p_stack->num=0;
  return;
}

void stack_deinit(stack* p_stack){
  p_stack->num=0;
  return;
}

int stack_size(const stack* p_stack){
  return p_stack->num;
}
int stack_empty(const stack* p_stack){
  return !p_stack->num;
}
int stack_full(const stack* p_stack){
  return p_stack->num==SIZE;
}

int stack_push(stack* p_stack, int val){
  if(stack_full(p_stack))
    return -1;
  else
  {
    p_stack->buf[p_stack->num] = val;
    p_stack->num++;
    return 0;
  }
}

int stack_pop(stack* p_stack, int *pval){
  if(stack_empty(p_stack))
  {
    return -1;
  }
  else
  {
    *pval = p_stack->buf[p_stack->num-1];
    p_stack->num--;
    return 0;
  }
}
int stack_top(const stack* p_stack, int *pval){
  if(stack_empty(p_stack))
  {
    return -1;
  }
  else
  {
    *pval= p_stack->buf[p_stack->num-1];
    return 0;
  }
}
