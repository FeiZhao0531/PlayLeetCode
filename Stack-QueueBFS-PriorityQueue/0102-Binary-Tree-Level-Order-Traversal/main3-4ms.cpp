/// Source : https://leetcode.com/problems/binary-tree-level-order-traversal/description/
/// Author : Fei
/// Time   : Jun-10-2019

#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/// Recursive, seems faster but more space
/// Time Complexity: O(h), where n is the number of nodes
/// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        this->treeLevels = depth( root);
        vector< vector<int> > res( treeLevels, vector<int>());
        levelOrder( root, res, 0);

        return res;
    }
private:
    int treeLevels = 0;
    int depth( TreeNode* root) {

        if( !root)
            return 0;
        return 1 + max( depth( root->left), depth( root->right));
    }

    void levelOrder( TreeNode* node, vector< vector<int> >& res, int level) {

        if( !node)
            return;
        assert( level < treeLevels);
        res[ level].push_back( node->val);
        levelOrder( node->left, res, level + 1);
        levelOrder( node->right, res, level + 1);
    }
};

int main() {

    return 0;
}
