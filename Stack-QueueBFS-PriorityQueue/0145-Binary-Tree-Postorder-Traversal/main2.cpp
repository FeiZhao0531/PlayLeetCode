/// Source : https://leetcode.com/problems/binary-tree-postorder-traversal/description/
/// Author : Fei
/// Time   : Jun-10-2019

#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// My Non-Recursive
// Time Complexity: O(n), n is the node number in the tree
// Space Complexity: O(h), h is the height of the tree
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int> res;
        if(root == NULL)
            return res;
        stack< pair< TreeNode*, bool> > stk; // bool( true: visit the val of node; false: go to this node)
        stk.push( make_pair( root, false));
        while( !stk.empty()) {
            pair<TreeNode*, bool> p = stk.top();
            stk.pop();
            if( p.second == true)
                res.push_back( p.first->val);
            else {
                stk.push( make_pair( p.first, true));
                if( p.first->right)
                    stk.push( make_pair( p.first->right, false));
                if( p.first->left)
                    stk.push( make_pair( p.first->left, false));
            }
        }

        return res;
    }
};

int main() {

    return 0;
}

