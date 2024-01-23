#include "BinaryTree.h"
#include "BalanceTree.h"
#include <iostream>

void print_val(int x)
{
  std::cout << x << " ";
}

int main()
{
  BinaryTree tree;
  tree.Insert(15);
  tree.Insert(48);
  tree.Insert(25);
  tree.Insert(37);
  tree.Insert(23);
  tree.Insert(45);
  tree.Insert(47);
  tree.Insert(67);
  tree.MidOrdTrav(print_val);
  std::cout << "\n";
  tree.Remove(37);
  tree.Remove(47);
  tree.MidOrdTrav(print_val);
  std::cout << "\n";

  // 平衡树测试
  BalanceTree btTree;
  btTree.Insert(10);
  btTree.Insert(20);
  btTree.Insert(30);
  btTree.Insert(40);
  btTree.Insert(50);
  btTree.Insert(60);
  btTree.Remove(40);
  btTree.inorderTraversal(print_val);
  std::cout << "\n";
  std::cout << "是否是平衡树: " << btTree.IsBalTree() << std::endl;

  return 0;
}