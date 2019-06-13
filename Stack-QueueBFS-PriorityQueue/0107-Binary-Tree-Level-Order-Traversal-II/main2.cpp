/// Source : https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
/// Author : Fei
/// Time   : Jun-10-2019

#include <iostream>

using namespace std;

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

/// Recursive
///
/// Time Complexity: O(n), where n is the number of nodes in the tree
/// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        this->treeLevels = depth( root);
        vector< vector<int> > res( treeLevels, vector<int>());
        levelOrderBottom( root, res, treeLevels - 1);

        return res;
    }
private:
    int treeLevels = 0;

    int depth( TreeNode* node) {

        if( !node)
            return 0;
        return 1 + max( depth( node->left), depth( node->right));
    }

    void levelOrderBottom( TreeNode* node, vector< vector<int> >& res, int level) {

        if( !node) return;
        assert( level >= 0);
        res[ level].push_back( node->val);
        levelOrderBottom( node->left, res, level - 1);
        levelOrderBottom( node->right, res, level - 1);
    }
};


int main() {

    return 0;
}
