#include "BinarySearchTree.h"

void print_inorder(const BinarySearchTree &bst)
{
    print_inorder(bst.root());
}