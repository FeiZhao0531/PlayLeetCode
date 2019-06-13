/// Source : https://leetcode.com/problems/binary-tree-preorder-traversal/description/
/// Author : Fei
/// Time   : Jun-10-2019

#include <iostream>
#include <vector>
#include <stack>
#include <cassert>

using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Classic Non-Recursive algorithm for preorder traversal
// Time Complexity: O(n), n is the node number in the tree
// Space Complexity: O(h), h is the height of the tree
class Solution {

public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> res;
        if(root == NULL)
            return res;

        stack<TreeNode*> stk;
        stk.push(root);
        while( !stk.empty()){
            TreeNode* curNode = stk.top();
            stk.pop();
            res.push_back( curNode->val);

            if( curNode->right)
                stk.push(curNode->right);
            if( curNode->left)
                stk.push(curNode->left);
        }

        return res;
    }
};

int main() {

    return 0;
}
