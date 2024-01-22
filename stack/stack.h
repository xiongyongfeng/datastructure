#ifndef _STACK_H_
#define _STACK_H_
typedef struct{
  int buf[SIZE];
  int num;
}stack;

void stack_init(stack* p_stack);
void stack_deinit(stack* p_stack);

int stack_size(const stack* p_stack);
int stack_empty(const stack* p_stack);
int stack_full(const stack* p_stack);

int stack_push(stack* p_stack, int val);
int stack_pop(stack* p_stack, int *pval);
int stack_top(const stack* p_stack, int *pval);
#endif
