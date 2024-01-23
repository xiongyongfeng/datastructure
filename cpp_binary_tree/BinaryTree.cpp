#include "BinaryTree.h"

BinaryTree::TreeNode *BinaryTree::Insert(TreeNode *node, int val)
{
  if (node == nullptr)
  {
    return new TreeNode(val);
  }
  else if (node->val > val) // 在左侧插入
  {
    /* code */
    node->left = Insert(node->left, val);
  }
  else if (node->val < val) // 在右侧插入
  {
    /* code */
    node->right = Insert(node->right, val);
  }
  return node;
}

BinaryTree::TreeNode *BinaryTree::FindMaxLeftNode(TreeNode *node)
{
  // 调用此函数时默认左侧字数存在,为了通用性,依然对不存在的情况进行了处理
  TreeNode *tmp = node->left;
  while (1)
  {
    if (!tmp->right)
    {
      break;
    }
    tmp = tmp->right;
  }
  return tmp;
}
BinaryTree::TreeNode *BinaryTree::Remove(TreeNode *node, int val)
{
  if (node == nullptr)
  {
    return node;
  }
  else if (node->val == val)
  {
    /* code */
    // 是否是叶子节点
    if (node->left == nullptr)
    {
      TreeNode *tmp = node;
      node = node->right;
      delete tmp;
      tmp = nullptr;
    }
    else if (node->right == nullptr)
    {
      TreeNode *tmp = node;
      node = node->left;
      delete tmp;
      tmp = nullptr;
    }
    else // 左右子节点都存在,查找左子树的最大值,与node->val交换,在左子树递归删除val
    {
      TreeNode *tmp = FindMaxLeftNode(node);
      node->val = tmp->val;
      node->left = Remove(node->left, val);
    }
  }
  else if (node->val > val) // 在左侧递归删除val
  {
    /* code */
    node->left = Remove(node->left, val);
  }
  else if (node->val < val) // 右侧递归删除val
  {
    /* code */
    node->right = Remove(node->right, val);
  }
  return node;

  // 查找是否存在val
  // 如果存在
}
void BinaryTree::MidOrdTrav(TreeNode *node, pFunc pF)
{
  if (node == nullptr)
  {
    return;
  }
  MidOrdTrav(node->left, pF);
  pF(node->val);
  MidOrdTrav(node->right, pF);
}