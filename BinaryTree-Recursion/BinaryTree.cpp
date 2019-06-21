/// create : Jun-18-2019
/// author : Fei

#include "BinaryTree.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <queue>

using namespace std;

BinaryTree::BinaryTree( const vector<int>& preOrderVec, const vector<int>& inOrderVec)
{
    assert( preOrderVec.size() == inOrderVec.size());

    _root = _buildTree( preOrderVec, 0, preOrderVec.size()-1, inOrderVec, 0, inOrderVec.size()-1);
}

TreeNode* BinaryTree::_buildTree( const vector<int>& preorder, int ps, int pe,
                                  const vector<int>& inorder, int is, int ie)
{

    if( is > ie)
        return NULL;

    TreeNode* node = new TreeNode( preorder[ps]);
    _size ++;

    int index = is;
    for( ; index<=ie; ++index)
        if( inorder[ index] == preorder[ ps])
            break;
    assert( index != ie + 1);

    node->left = _buildTree( preorder, ps+1, ps+index-is, inorder, is, index-1);
    node->right = _buildTree( preorder, ps+index-is+1, pe, inorder, index+1, ie);

    return node;
}

void BinaryTree::deleteNode( TreeNode* node) {

    if( node != NULL) {
        deleteNode( node->left);
        deleteNode( node->right);

        delete node;
        node = NULL;
        _size --;
    }
}

int BinaryTree::subTreeNodes( TreeNode* node) {

    if( !node)
        return 0;

    return 1 + subTreeNodes( node->left) + subTreeNodes( node->right);

}

void BinaryTree::levelOrderPrint( TreeNode* root) {

    if( !root) {
        cout<<"NULL"<<endl;
        return;
    }
    vector<string> record;
    queue< TreeNode*> q;
    q.push( root);
    while( !q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if( node) {
            record.push_back( to_string( node->val));
            q.push( node->left);
            q.push( node->right);
        }
        else
            record.push_back( "NULL");
    }
    for( string s : record)
        cout<< s <<", ";
    cout<< endl;
    return;
}


