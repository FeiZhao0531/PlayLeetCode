/// Source : https://leetcode.com/problems/count-complete-tree-nodes/
/// Author : Fei
/// Time   : Jun-19-2019

#include "../BinaryTree.h"
#include "../BinaryTree.cpp"
#include <iostream>
#include <cassert>

using namespace std;

/// Recursion
/// Time Complexity: O(n)
/// Space Complexity: O(h)
class Solution {
public:
    int countNodes(TreeNode* root) {

        if( !root)
            return 0;

        return 1 + countNodes( root->left) + countNodes( root->right);
    }
};


int main() {

    TreeNode* root = new TreeNode(1);

    TreeNode* left = new TreeNode(2);
    root->left = left;

    TreeNode* right = new TreeNode(3);
    root->right = right;

    TreeNode* leftleft = new TreeNode(4);
    root->left->left = leftleft;

    TreeNode* leftright = new TreeNode(5);
    root->left->right = leftright;

    TreeNode* rightleft = new TreeNode(6);
    root->right->left = rightleft;

    cout << Solution().countNodes(root) << endl;

    return 0;
}
