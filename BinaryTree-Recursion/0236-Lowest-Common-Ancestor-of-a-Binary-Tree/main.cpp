/// Source : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
/// Author : Fei
/// Time   : Jun-22-2019

#include <iostream>
#include <cassert>

using namespace std;

/// Recursion implementation
/// Time Complexity: O(n)
/// Space Complexity: O(n)

///Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if( !root || root == p || root == q)
            return root;

        TreeNode* lNode = lowestCommonAncestor( root->left, p, q);
        TreeNode* rNode = lowestCommonAncestor( root->right, p, q);

        if( lNode && rNode)
            return root;
        return lNode ? lNode : rNode;
    }
};


int main() {

    return 0;
}
