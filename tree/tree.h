#ifndef __TREE_H__
#define __TREE_H__
struct node;

typedef struct tree{
   struct node* p_node;
}tree;

typedef struct node{
  int val;
  tree left;
  tree right;
}node;

//初始化
void tree_init(tree* p_tree);

//清空tree
int tree_deinit(tree* p_tree);

//有序二叉树中查找val,返回对应的tree
tree* tree_search(const tree* p_tree, int val);

int tree_insert(tree* p_tree, int val);


//树的遍历
//中序遍历
typedef void(*pfunc_t)(int);
void tree_miter(const tree* p_tree, pfunc_t p_func);
#endif
