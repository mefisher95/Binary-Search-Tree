#include "BinarySearchTreeNode.h"

std::ostream &operator<<(std::ostream &cout, 
                         const BinarySearchTreeNode &node)
{
    cout << "<Node: " << &node
         << ", key: " << node.key()
         << ", parent: " << node.parent()
         << ", left: " << node.left()
         << ", right: " << node.right() << '>';
    
    return cout;
}

void print_inorder(const BinarySearchTreeNode *node)
{
    if (node == NULL) return;
    print_inorder(node->left());
    std::cout << (*node) << '\n';
    print_inorder(node->right());
}

bool insert(BinarySearchTreeNode* &node, int x)
{
    if (node == NULL)
    {
        node = new BinarySearchTreeNode(x);
        return true;
    }
    else if (node->key() < x)
    {
        if (node->right() == NULL)
        {
            node->right() = new BinarySearchTreeNode(x, node);
            return true;
        }
        else
        {
            return insert(node->right(), x);
        }
    }
    else if (node->key() > x)
    {
        if (node->left() == NULL)
        {
            node->left() = new BinarySearchTreeNode(x, node);
            return true;
        }
        else 
        {
            return insert(node->left(), x);
        }
    }
    else return false;
}