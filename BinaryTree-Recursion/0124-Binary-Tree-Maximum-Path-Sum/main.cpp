/// Source : https://leetcode.com/problems/binary-tree-maximum-path-sum/
/// Author : Fei
/// Time   : Jun-23-2019

#include "../BinaryTree.cpp"
#include "../BinaryTree.h"
#include <iostream>
#include <vector>

using namespace std;

/// Recursive, same as LeetCode 437 Path Sum III
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maxPathSum(TreeNode* root) {

        maxPathSumFromRoot( root);
        return maxSum;
    }
private:
    int maxSum = INT_MIN;
    int maxPathSumFromRoot( TreeNode* root) {

        if( !root)
            return 0;

        int sumFromRoot = root->val;
        int lSum = maxPathSumFromRoot( root->left);
        lSum = lSum < 0 ? 0 : lSum;
        sumFromRoot += lSum;
        int rSum = maxPathSumFromRoot( root->right);
        rSum = rSum < 0 ? 0 : rSum;
        sumFromRoot += rSum;
        maxSum = max( maxSum, sumFromRoot);
        int res = root->val + max( lSum, rSum);

        return res;
    }
};


int main() {

    vector<int> preVec{ 5, 3, 2, 4, 6, 7};
    vector<int> inVec{ 2, 3, 4, 5, 6, 7};
    BinaryTree binTree( preVec, inVec);
    TreeNode* root = binTree.getRootNode();
    cout << " max Path Sum = " << Solution().maxPathSum( root);
    return 0;
}
