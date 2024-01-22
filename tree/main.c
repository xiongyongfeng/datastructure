#include "tree.h"
#include <stdio.h>
void print_val(int val){
  printf("%d ",val);
}
int main(){
  tree tr;
  tree_init(&tr);
  tree_insert(&tr,50);
  tree_insert(&tr,25);
  tree_insert(&tr,75);
  tree_insert(&tr,13);
  tree_insert(&tr,37);
  tree_insert(&tr,67);
  tree_insert(&tr,88);
  tree_insert(&tr,7);
  tree_miter(&tr,print_val);
  printf("\n");
  tree_deinit(&tr);
  return 0;
}
