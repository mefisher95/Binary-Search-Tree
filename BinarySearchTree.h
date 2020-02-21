// File: BinarySearchTree.h

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H  

#include <vector>
#include "BinarySearchTreeNode.h"

class ValueError{};

class BinarySearchTree
{
    public:
    BinarySearchTree()
    : root_(NULL)
    {}

    // Put x[0], x[1], ..., x[size - 1] into the tree
    /*BinarySearchTree(int x[], int size)
    {}

    BinarySearchTree(const BinarySearchTree &bst)
    {}

    BinarySearchTree()
    {}*/

    BinarySearchTreeNode* root() const { return root_; }

    // [HINT: Traverse *this and bst.]
    BinarySearchTree &operator=(const BinarySearchTree &bst)
    {
        return (*this);
    }

    BinarySearchTreeNode* get_root() const { return root_; }

    void clear()
    {
        _clear(root_);
        root_ = NULL;
    }

    // return true if the tree is empty
    bool is_empty() const
    {
        if (root_ == NULL) return true;
        return false;   
    }


    // returns the height of the tree. note that the height
    // of an empty try is -1
    int height() const
    {
        int height = -1;
        height = _height(root_);
        return height;

        return 0;   
    }

    // return sthe depth of the node ointer p parameter. this is
    // the number of edges from the root to the node that p
    // points to.
    int depth(BinarySearchTreeNode* p)
    {
        if (p->parent() == NULL) return 0;
        else return depth(p->parent()) + 1;
    }

    // returns the number of nodes in this tree.
    int size() const { return _size(root_); }

    // todo
    // returns a pointer to the node containing x. if x is not
    // in the tree, NULL is returned
    BinarySearchTreeNode* find(int x) { return _find(root_, x); }

    // todo
    // returns the minimus value in the tree. if the tree is empty
    // a valueError exception object is thrown
    int min() const 
    { 
        int min = root_->key();
        _min(root_, min);
        return min; 
    }

    // todo 
    // returns the maximus value in the tree. if the tree is empty
    // a value error is thrown
    int max() const 
    { 
        int max = root_->key();
        _max(root_, max);
        return max;  
    }

    // todo returns true if *this and t are the same trees,
    // i.e., the values and structure of *this and t are the same.
    bool operator==(const BinarySearchTreeNode &t)
    {
        return true;
    }

    // todo
    // inserts x into the tree. if x is already in the tree, 
    // a ValueError is thrown
    void insert(int x)
    {
        bool success = ::insert(root_, x);
        if (!success) throw ValueError();
    }

    // remove x from the tree. if x is not in the tree,
    // a valueError exception is thrown
    void remove(int x) 
    {
        BinarySearchTreeNode* n = find(x);
        _bst_delete(root_, n);
    }

    // todo 
    // returns a vector of integers built by traversing the tree
    // using inorder traversal
    std::vector< int > inorder()
    {
        std::vector< int > ret;
        _inorder_vect(root_, ret);
        return ret;
    }

    // todo
    // returns a vector of integers built by traversing the tree
    // using preorder traversal
    std::vector< int > preorder()
    {
        std::vector< int > ret;
        _preorder_vect(root_, ret);
        return ret;
    }

    // todo
    // returns a vector of integers built by traversing the tree
    // using postorder traversal
    std::vector< int > postorder()
    {
        std::vector< int > ret;
        _postorder_vect(root_, ret);
        
        return ret;
    }

    // todo 
    // returns a vector of integers built by traversing the tree
    // using breadth first traversal
    std::vector< int > breadthfirst() const
    {
        std::vector< int > ret;
        return ret;
    }   

    // todo 
    // return pointer to k-th ordered node
    // [HINT: Use a traversal]
    BinarySearchTreeNode* select(int k)
    {
        int count = 0;
        return _select(root_, count, k);
    }

    // todo
    // return vector of integers in tree with key values
    // <= m and < M. 
    std::vector< int > range(int m, int M)
    {
        std::vector< int > ret;
        _range(root_, ret, m, M);
        return ret;
    }

    //*************************************************************************
    // The following iterators are optional. (These are somewhat challenging.)
    // This is how the iterator would be used:
    //
    //   BinarySearchTree::inorder_iterator p = tree.begin();
    //   while (p != tree.end())
    //   {
    //       std::cout << *p << std::endl;
    //       p++;
    //   }
    //
    // Note that you should be as memory efficient as possible. So for instance
    // Performing a complete traversal, storing a vector of the nodes, and
    // iterating through this vector is not allowed.

    /*
    class inoder_iterator
    {
        public:
        BinarySearchTreeNode* operator*()
        {}
        void operator++() {}
        void operator++(int) {}
        void operator--() {}
        void operator++(int) {}
        //etc.

    };*/

    private:
    BinarySearchTreeNode* root_;

    void _clear(BinarySearchTreeNode* n)
    {
        if (n == NULL) return;
        else
        {
            _clear(n->left());
            _clear(n->right());
            n->parent() = NULL;
            n->left() = NULL;
            n->right() = NULL;
            delete n;
            return;
        }
        throw ValueError();
    }

    int _height(BinarySearchTreeNode* n) const
    {
        if (n == NULL) return -1;
        else
        {
            int x = _height(n->right()) + 1;
            int y = _height(n->left()) + 1;

            if (x >= y) return x;
            else return y;
        }
        
    }

    BinarySearchTreeNode* _find(BinarySearchTreeNode* n, int key)
    {
        if (n == NULL) return NULL;

        if (n->key() == key) return n;
        else
        {
            if (key < n->key()) return _find(n->left(), key);
            else return _find(n->right(), key);
        }
    }

    int _size(BinarySearchTreeNode* n) const
    {
        if (n == NULL) return 0;
        else 
        {
            return (_size(n->right()) + _size(n->left()) + 1);
        }
    }

    void _min(BinarySearchTreeNode* n, int &min) const
    {
        if (n == NULL) return;
        if (n->key() < min) min = n->key();
        _min(n->left(), min);
        _min(n->right(), min);
    }        

    void _max(BinarySearchTreeNode* n, int &max) const
    {
        if (n == NULL) return;
        if (n->key() > max) max = n->key();
        _max(n->left(), max);
        _max(n->right(), max);
    }     

    BinarySearchTreeNode* _find_pred(BinarySearchTreeNode* n) const
    {
        if (n == NULL) return NULL;
        if (n->left() = NULL) return NULL;
        return n->left()->rightmost();
    }   

    BinarySearchTreeNode* _find_succ(BinarySearchTreeNode* n) const
    {
        if (n == NULL) return NULL;
        if (n->right() = NULL) return NULL;
        return n->right()->leftmost();
    }

    void _bst_delete(BinarySearchTreeNode* proot,
                     BinarySearchTreeNode* p)
    {
        if (p->left() == NULL)
        {
            if (p->right() == NULL)
            _bst_delete_leaf(proot, p);
            else
            _bst_move_succ_up(proot, p);
        }
        else
        {
            if (p->right() == NULL)
            _bst_move_pred_up(proot, p);
            else // two children case
            {
                if (rand() % 2 == 0)
                _bst_move_pred_up(proot, p);
                else
                _bst_move_succ_up(proot, p);                
            }
        }
    }

    BinarySearchTreeNode* &PCP(BinarySearchTreeNode* p)
    {
        BinarySearchTreeNode* parent = p->parent();
        if (parent->left() == p) return parent->left();
        else return parent->right();
    }


    void _bst_delete_leaf(BinarySearchTreeNode* proot,
                          BinarySearchTreeNode* p)
    {
        if (p == proot) proot = NULL;
        else PCP(p) = NULL;
        delete p;
    }

    void _bst_move_pred_up(BinarySearchTreeNode* remove, 
                       BinarySearchTreeNode* pred)
    {
        // p = remove, q = pred
        if (pred != remove->left())
        {
            pred->parent()->right() = pred->left();
        }
        else
        {
            _bst_move_pred_up(remove, pred->left());
        }
        remove->key() = pred->key();
    }

    void _bst_move_succ_up(BinarySearchTreeNode* remove, 
                       BinarySearchTreeNode* pred)
    {
        // p = remove, q = pred
        if (pred != remove->right())
        {
            pred->parent()->left() = pred->right();
        }
        else
        {
            _bst_move_succ_up(remove, pred->right());
        }
        remove->key() = pred->key();
    }

    void _preorder_vect(BinarySearchTreeNode* n, std::vector< int > &ret)
    {
        if (n == NULL) return;
        ret.push_back(n->key());
        _preorder_vect(n->left(), ret);
        _preorder_vect(n->right(), ret);
    }

    void _inorder_vect(BinarySearchTreeNode* n, std::vector< int > &ret)
    {
        if (n == NULL) return;
        _inorder_vect(n->left(), ret);
        ret.push_back(n->key());
        _inorder_vect(n->right(), ret);
    }

    void _postorder_vect(BinarySearchTreeNode* n, std::vector< int > &ret)
    {
        if (n == NULL) return;
        _postorder_vect(n->left(), ret);
        _postorder_vect(n->right(), ret);
        ret.push_back(n->key());
    }

    BinarySearchTreeNode* _select(BinarySearchTreeNode* n, int &count, int target)
    {
        if (target == count) return n;
        ++count;
        _select(n->left(), count, target);
        _select(n->right(), count, target);
    }

    void _range(BinarySearchTreeNode* n, std::vector< int > ret, int m, int M)
    {
        if (n == NULL) return;
        if (n->key() >= m || n->key() <= M) ret.push_back(n->key());
        _range(n->left(), ret, m, M);
        _range(n->right(), ret, m, M);
    }
    
};

void print_inorder(const BinarySearchTree &bst);
void print_preorder(const BinarySearchTreeNode &bst);
void print_postorder(const BinarySearchTreeNode &bst);

#endif