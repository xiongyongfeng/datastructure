#include "BalanceTree.h"
#include <algorithm>
#include <iostream>

int BalanceTree::GetHeight(TreeNode *node)
{
  if (node == nullptr)
  {
    return -1;
  }

  return node->m_nHeight;
}
int BalanceTree::GetBanlance(TreeNode *node)
{
  if (node == nullptr)
  {
    return 0;
  }
  return GetHeight(node->m_pLeft) - GetHeight(node->m_pRight);
}

void BalanceTree::UpdateHeight(TreeNode *node)
{
  if (node == nullptr)
  {
    return;
  }
  node->m_nHeight = std::max(GetHeight(node->m_pLeft), GetHeight(node->m_pRight)) + 1;
}

BalanceTree::TreeNode *BalanceTree::LRotate(TreeNode *node)
{
  TreeNode *child = node->m_pRight;
  node->m_pRight = child->m_pLeft;
  child->m_pLeft = node;
  node = child;

  // 更新height
  UpdateHeight(node->m_pLeft);
  UpdateHeight(node);
  return node;
}

BalanceTree::TreeNode *BalanceTree::RRotate(TreeNode *node)
{
  TreeNode *child = node->m_pLeft;
  node->m_pLeft = child->m_pRight;
  child->m_pRight = node;
  node = child;
  // 更新height
  UpdateHeight(node->m_pRight);
  UpdateHeight(node);
  return node;
}

BalanceTree::TreeNode *BalanceTree::InsertRec(TreeNode *node, int val)
{
  if (node == nullptr)
  {
    return new TreeNode(val);
  }
  else if (val == node->m_nVal)
  {
    return node;
  }
  else if (val < node->m_nVal)
  {
    node->m_pLeft = InsertRec(node->m_pLeft, val);
    UpdateHeight(node);
    if (GetBanlance(node) > 1) // 需要再平衡
    {
      // left-left型, 一次右旋
      if (GetHeight(node->m_pLeft->m_pLeft) >= 0 && GetHeight(node->m_pLeft->m_pRight) <= 0)
        node = RRotate(node);

      // left-right型,一次左旋,一次右旋
      if (GetHeight(node->m_pLeft->m_pRight) >= 0 && GetHeight(node->m_pLeft->m_pLeft) <= 0)
      {
        node->m_pLeft = LRotate(node->m_pLeft); // 左旋一次
        node = RRotate(node);                   // 右旋一次
      }
    }
  }
  else
  {
    node->m_pRight = InsertRec(node->m_pRight, val);
    UpdateHeight(node);
    if (GetBanlance(node) < -1) // 需要再平衡
    {
      if (GetHeight(node->m_pRight->m_pRight) >= 0 && GetHeight(node->m_pRight->m_pLeft) <= 0)
        node = LRotate(node);

      // right-left型,一次右旋,一次左旋
      if (GetHeight(node->m_pRight->m_pLeft) >= 0 && GetHeight(node->m_pRight->m_pRight) <= 0)
      {
        node->m_pRight = RRotate(node->m_pRight); // 左旋一次
        node = LRotate(node);                     // 右旋一次
      }
    }
  }
  return node;
}
BalanceTree::TreeNode *BalanceTree::RemoveRec(TreeNode *node, int val)
{
  if (node == nullptr)
  {
    return node; // 查找是否存在此节点,如果不存在,则不执行操作
  }
  if (val < node->m_nVal)
  {
    node->m_pLeft = RemoveRec(node->m_pLeft, val);
  }
  else if (val > node->m_nVal)
  {
    node->m_pRight = RemoveRec(node->m_pRight, val);
  }
  else
  {
    // 如果存在
    // 1.判断此节点是否是叶子节点,如果是叶子节点,直接删除,父节点指向其的指针置空
    // 2.如果此节点存在一个子节点,则父节点指向其的指针指向其子节点
    if (node->m_pLeft == nullptr || node->m_pRight == nullptr)
    {
      TreeNode *tmp;
      tmp = node;
      if (node->m_pLeft == nullptr)
        node = node->m_pRight;
      else
        node = node->m_pLeft;
      delete tmp;
      tmp = nullptr;

      // 评估是否打破平衡
      if (GetBanlance(node) < -1)
      {
        if (GetHeight(node->m_pRight->m_pRight) >= 0 && GetHeight(node->m_pRight->m_pLeft) <= 0)
          node = LRotate(node);

        // right-left型,一次右旋,一次左旋
        if (GetHeight(node->m_pRight->m_pLeft) >= 0 && GetHeight(node->m_pRight->m_pRight) <= 0)
        {
          node->m_pRight = RRotate(node->m_pRight); // 左旋一次
          node = LRotate(node);                     // 右旋一次
        }
      }
      else if (GetBanlance(node) > 1)
      {
        /* code */
        // left-left型, 一次右旋
        if (GetHeight(node->m_pLeft->m_pLeft) >= 0 && GetHeight(node->m_pLeft->m_pRight) <= 0)
          node = RRotate(node);

        // left-right型,一次左旋,一次右旋
        if (GetHeight(node->m_pLeft->m_pRight) >= 0 && GetHeight(node->m_pLeft->m_pLeft) <= 0)
        {
          node->m_pLeft = LRotate(node->m_pLeft); // 左旋一次
          node = RRotate(node);                   // 右旋一次
        }
      }
    }
    else
    { // 3.如果存在两个节点
      TreeNode *pLeftMax = FindMaxLeft(node);
      node->m_nVal = pLeftMax->m_nVal;
      node->m_pLeft = RemoveRec(node->m_pLeft, node->m_nVal); // 真聪明
    }
  }
  return node;
}

BalanceTree::TreeNode *BalanceTree::FindMaxLeft(TreeNode *node)
{
  TreeNode *tmp = node->m_pLeft;
  while (1)
  {
    if (tmp->m_pRight == nullptr)
    {
      break;
    }
    tmp = tmp->m_pRight;
    /* code */
  }

  return tmp;
}

void BalanceTree::inorderTraversal(TreeNode *node, pFunc pF)
{
  if (node == nullptr)
  {
    return;
  }
  inorderTraversal(node->m_pLeft, pF);
  pF(node->m_nVal);
  inorderTraversal(node->m_pRight, pF);
}

bool BalanceTree::IsBalTree(TreeNode *node)
{
  if (node == nullptr)
  {
    return true;
  }
  if (std::abs(GetBanlance(node)) < 2 && IsBalTree(node->m_pLeft) && IsBalTree(node->m_pRight))
  {
    return true;
  }
  else
  {
    return false;
  }
}

void BalanceTree::printNode(TreeNode *node)
{
  std::cout << "node value = " << node->m_nVal << ", node height = " << node->m_nHeight << std::endl;
}
