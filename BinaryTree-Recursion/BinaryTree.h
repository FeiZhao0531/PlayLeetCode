/// create : Jun-18-2019
/// author : Fei

#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <cstdlib>
#include <vector>
#include <iostream>

struct TreeNode {

    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode( int x) : val(x), left( NULL), right( NULL) {}
};

class BinaryTree
{
    private:
        TreeNode*       _root; // root node
        int             _size; // size of nodes in this tree
        TreeNode*       _buildTree( const std::vector<int>& pre, int ps, int pe, const std::vector<int>& in, int is, int ie);

    public:
        BinaryTree() :  _size(0), _root( NULL) {};
        BinaryTree( const std::vector<int>& preOrderVec, const std::vector<int>& inOrderVec);
            // preOrder and inOrder transversal to create a BinaryTree

        virtual         ~BinaryTree() { if( _size > 0) deleteNode( _root);}
        int             size() const { return _size;}
        bool            empty() const { return !_root;}
        TreeNode*       getRootNode() const { return _root;}
        void            deleteNode( TreeNode* node);
            // delete the sub-tree started from this node
        int             subTreeNodes( TreeNode* node);
            // return the size of sub-tree started from this node
        void            levelOrderPrint( TreeNode* root);
            // print the Binary Tree in level order( same as LeetCode test case)

    protected:

};

#endif // BINARYTREE_H
