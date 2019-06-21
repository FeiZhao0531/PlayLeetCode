/// Source : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
/// Author : Fei
/// Time   : Jun-19-2019

#include "../BinaryTree.cpp"
#include "../BinaryTree.h"
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Recursive
/// Time Complexity: O(n*h) where n is the amount of node in the tree
///                         and h is the height of the tree
/// Space Complexity: O(h)
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        assert( preorder.size() == inorder.size());
        return _buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

private:
    TreeNode* _buildTree(const vector<int>& preorder, int pL, int pR,
                        const vector<int>& inorder, int iL, int iR) {

        if(iL > iR){
            assert( pL > pR);
            return NULL;
        }

        TreeNode* node = new TreeNode( preorder[ pL]);
        int nodeIndexInorder = iL;
        for( ; nodeIndexInorder <= iR; ++nodeIndexInorder)
            if( inorder[ nodeIndexInorder] == preorder[ pL])
                break;
        assert( nodeIndexInorder <= iR);

        node->left = _buildTree( preorder, pL + 1, pL + nodeIndexInorder - iL, inorder, iL, nodeIndexInorder - 1);
        node->right = _buildTree( preorder, pL + nodeIndexInorder - iL + 1, pR, inorder, nodeIndexInorder + 1, iR);
        return node;
    }
};


int main() {

    vector<int> preOrderVec { 3, 9, 20, 15, 7};
    vector<int> inOrderVec { 9, 3, 15, 20 ,7};
    BinaryTree binTree;
    TreeNode* root = Solution().buildTree( preOrderVec, inOrderVec);
    binTree.levelOrderPrint( root);
    //Solution().buildTree( preOrderVec, inOrderVec);
    return 0;
}
