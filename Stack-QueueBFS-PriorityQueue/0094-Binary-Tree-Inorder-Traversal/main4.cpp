/// Source : https://leetcode.com/problems/binary-tree-inorder-traversal/
/// Author : Fei
/// Time   : Jun-09-2019

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// Traditional method by stack
// Time Complexity: O(n), n is the node number in the tree
// Space Complexity: O(h), h is the height of the tree
class Solution {

public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> res;
        if( !root)
            return res;
        stack< TreeNode*> stk;
        stk.push( root));
        while( !stk.empty()) {
            while( stk.top()->left)
                stk.push( stk.top()->left);
            while( !stk.empty()) {
                TreeNode* node = stk.top();
                stk.pop();
                res.push_back( node->val);
                if( node->right) {
                    stk.push( node->right);
                    break;
                }
            }
        }

        return res;
    }
};

int main() {

    return 0;
}
