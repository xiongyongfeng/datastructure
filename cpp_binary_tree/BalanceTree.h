#ifndef _BALANCETREE_H_
#define _BALANCETREE_H_

typedef void (*pFunc)(int);

class BalanceTree
{
  struct TreeNode
  {
    /* data */
    int m_nVal;
    int m_nHeight = {};
    TreeNode *m_pLeft = {};
    TreeNode *m_pRight = {};
    TreeNode(int v) : m_nVal(v) {}
  };

private:
  /* data */
  TreeNode *m_pRoot = {};

  int GetHeight(TreeNode *);
  int GetBanlance(TreeNode *);
  TreeNode *InsertRec(TreeNode *, int);
  TreeNode *RemoveRec(TreeNode *, int val);
  void UpdateHeight(TreeNode *);
  void inorderTraversal(TreeNode *, pFunc);
  TreeNode *LRotate(TreeNode *node);
  TreeNode *RRotate(TreeNode *node);
  bool IsBalTree(TreeNode *);
  void printNode(TreeNode *);
  TreeNode *FindMaxLeft(TreeNode *);

public:
  // BalanceTree(/* args */);
  // ~BalanceTree();
  void Insert(int val)
  {
    m_pRoot = InsertRec(m_pRoot, val);
  }
  void Remove(int val) { m_pRoot = RemoveRec(m_pRoot, val); };
  void inorderTraversal(pFunc pF) { inorderTraversal(m_pRoot, pF); }
  bool IsBalTree() { return IsBalTree(m_pRoot); }
};

#endif