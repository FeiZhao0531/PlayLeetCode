/// Source : https://leetcode.com/problems/count-complete-tree-nodes/
/// Author : Fei
/// Time   : Jun-19-2019

#include <iostream>
#include <cassert>

using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/// Recursion
/// Time Complexity: O(h^2) where h is the height of the tree
/// Space Complexity: O(h)
class Solution {
public:
    int countNodes(TreeNode* root) {

        int res = 0;
        if( !root)
            return res;

        int lHeight = _height( root->left);
        int rHeight = _height( root->right);
        if( lHeight == rHeight)
            res = ( 1 << lHeight) + countNodes( root->right);
        else
            res = ( 1 << rHeight) + countNodes( root->left);

        return res;
    }
private:
    int _height( TreeNode* node) {

        if( !node)
            return 0;

        int res = 1;
        while( node->left) {
            node = node->left;
            res ++;
        }

        return res;
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
