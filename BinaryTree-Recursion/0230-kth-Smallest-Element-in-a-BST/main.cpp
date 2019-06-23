/// Source : https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
/// Author : Fei
/// Time   : Jun-22-2019
#include <iostream>

using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/// Inorder Traversal
/// Time Complexity: O(n)
/// Space Complexity: O(h) where h is the height of the BST
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {

        vector<int> record;
        inorder( root, record);
        assert( k >= 1 && k <= record.size());

        return record[ k - 1];
    }

    void inorder( TreeNode* node, vector<int>& record) {

        if( !node)
            return;

        inorder( node->left, record);
        record.push_back( node->val);
        inorder( node->right, record);
    }
};


int main() {

    return 0;
}
