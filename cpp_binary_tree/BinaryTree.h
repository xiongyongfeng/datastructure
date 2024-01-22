typedef struct TreeNode
{
  /* data */
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
} TreeNode;

typedef void (*pFunc)(int);

class BinaryTree
{
private:
  /* data */
  TreeNode *m_pRoot;
  TreeNode *Insert(TreeNode *, int);
  TreeNode *FindMaxLeftNode(TreeNode *);
  TreeNode *Remove(TreeNode *, int);
  void MidOrdTrav(TreeNode *, pFunc);

public:
  BinaryTree(/* args */) { m_pRoot = nullptr; }
  void Insert(int val) { m_pRoot = Insert(m_pRoot, val); }
  void Remove(int val) { m_pRoot = Remove(m_pRoot, val); }
  void MidOrdTrav(pFunc pF) { MidOrdTrav(m_pRoot, pF); }
};
