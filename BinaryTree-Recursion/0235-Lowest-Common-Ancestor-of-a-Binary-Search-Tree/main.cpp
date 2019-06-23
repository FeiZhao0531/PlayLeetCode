/// Source : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
/// Author : Fei
/// Time   : Jun-21-2019

#include "../BinaryTree.cpp"
#include "../BinaryTree.h"
#include <iostream>
#include <cassert>

using namespace std;

/// Recursive
/// Time Complexity: O(lgn), where n is the node's number of the tree
/// Space Complexity: O(h), where h is the height of the tree
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        assert( !p && !q);

        if( !root) return root;

        if( p->val < root->val && q->val < root->val)
            return lowestCommonAncestor( root->left, p, q);
        if( p->val > root->val && q->val > root->val)
            return lowestCommonAncestor( root->right, p, q);

        assert( p->val == root->val || q->val == root->val
                || ( root->val - p->val) * ( root->val - q->val) < 0);

        return root;
    }
};

int main() {

    return 0;
}
