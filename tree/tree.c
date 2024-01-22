#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
//初始化
void tree_init(tree* p_tree){
  p_tree->p_node = NULL;
}

//清空tree
int tree_deinit(tree* p_tree){
  if(p_tree->p_node==NULL){
    return 0;
  }
  tree_deinit(&(p_tree->p_node->left));
  tree_deinit(&(p_tree->p_node->right));
  free(p_tree->p_node);
  p_tree->p_node = NULL;
  return 0;
}

//有序二叉树中查找val,返回对应的tree
tree* tree_search(const tree* p_tree, int val){
  if(p_tree->p_node==NULL){
    return (tree*)p_tree;
  }
  if(p_tree->p_node->val == val){
    return (tree*)p_tree;
  }
  else if(p_tree->p_node->val > val){ //需要到左子树中去找
    return tree_search(&(p_tree->p_node->left),val);
  }
  else{//需要到右子树中去找
    return tree_search(&(p_tree->p_node->right),val);
  }

}

int tree_insert(tree* p_tree, int val){
  tree* tmp = tree_search(p_tree,val);
  if(tmp->p_node!=NULL){ //说明找到了val, 不需要插入
    return 0;
  }
  node* p_node = NULL;
  p_node = (node*)malloc(sizeof(node));
  if(!p_node){
    printf("动态分配内存失败\n");
    return -1;
  }
  p_node->val = val;
  p_node->left.p_node = NULL;
  p_node->right.p_node=NULL;
  tmp->p_node = p_node;

  return 0;
}


//树的遍历
//中序遍历

void tree_miter(const tree* p_tree, pfunc_t p_func){
  if(p_tree->p_node==NULL){
    return;
  }
  tree_miter(&(p_tree->p_node->left),p_func);
  p_func(p_tree->p_node->val);
  tree_miter(&(p_tree->p_node->right),p_func);
  return;
}
