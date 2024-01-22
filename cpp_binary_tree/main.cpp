#include "BinaryTree.h"
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
  return 0;
}