/// Source : https://leetcode.com/problems/path-sum/description/
/// Author : Fei
/// Time   : Jun-20-2019

#include "../BinaryTree.cpp"
#include "../BinaryTree.h"
#include <iostream>

using namespace std;

/// Recursive
/// Time Complexity: O(n), where n is the nodes' number of the tree
/// Space Complexity: O(h), where h is the height of the tree
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {

        if( !root)
            return false;

        if( !root->left && !root->right)
            return sum == root->val;

        return hasPathSum( root->left, sum - root->val)
                || hasPathSum( root->right, sum - root->val);
    }
};


int main() {

    return 0;
}
