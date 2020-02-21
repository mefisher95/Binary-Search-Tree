// File: BinarySearchTreeNode.h

#ifndef BINARYSEARCHTREENODE_H
#define BINARYSEARCHTREENODE_H

#include <iostream>

class BinarySearchTreeNode
{
    public:
    BinarySearchTreeNode(int key,
                         BinarySearchTreeNode* parent = NULL,
                         BinarySearchTreeNode* left = NULL,
                         BinarySearchTreeNode* right = NULL)
    : key_(key), parent_(parent), left_(left), right_(right)
    {}

    int key() const { return key_; }
    int &key() { return key_; }

    BinarySearchTreeNode* parent() const { return parent_; }
    BinarySearchTreeNode* &parent() { return parent_; }

    BinarySearchTreeNode* root()
    {
        if (parent_ == NULL) return (this);
        BinarySearchTreeNode* temp = this;
        while(temp->parent_ != NULL)
        {
            temp = temp->parent_;
        }
        return temp;
    }

    BinarySearchTreeNode* left() const { return left_; }
    BinarySearchTreeNode* &left() { return left_; }
    BinarySearchTreeNode* leftmost()
    { 
        if (left_ == NULL) return (this);
        BinarySearchTreeNode* temp = this;
        while(temp->left_ != NULL)
        {
            temp = temp->left_;
        }
        return temp;
    }
    
    BinarySearchTreeNode* right() const { return right_; }
    BinarySearchTreeNode* &right() { return right_; }
    BinarySearchTreeNode* rightmost()
    {
        if (right_ == NULL) return (this);
        BinarySearchTreeNode* temp = this;
        while(temp->right_ != NULL)
        {
            temp = temp->right_;
        }
        return temp;
    }

    bool is_leaf() const
    {
        if (right_ != NULL || left_ != NULL) return false;
        return true;
    }

    bool is_nonleaf() const
    {
        if (is_leaf()) return false;
        return true;
    }   

    bool is_root() const
    {
        if (parent_ == NULL) return true;
        return false;
    }

    private:
    int key_; 
    BinarySearchTreeNode* parent_;
    BinarySearchTreeNode* left_;
    BinarySearchTreeNode* right_; 
};

std::ostream &operator<<(std::ostream &,
                         const BinarySearchTreeNode &);

void print_inorder(const BinarySearchTreeNode*);
bool insert(BinarySearchTreeNode* &, int);

#endif