/// Source : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
/// Author : Fei
/// Time   : Jun-22-2019

#include <iostream>
#include <vector>

using namespace std;


/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/// Recursion
/// Time Complexity: O(n)
/// Space Complexity: O(logn)
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        return sortedArrayToBST( nums, 0, nums.size() - 1);
    }

    TreeNode* sortedArrayToBST( vector<int>& nums, int l, int r) {

        if( l > r)
            return NULL;

        int mid = l + ( r - l) / 2;
        TreeNode* node = new TreeNode( nums[mid]);
        node->left = sortedArrayToBST( nums, l, mid - 1);
        node->right = sortedArrayToBST( nums, mid + 1, r);

        return node;
    }
};


int main() {

    return 0;
}
