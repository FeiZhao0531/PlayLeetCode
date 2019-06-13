/// Source : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
/// Author : Fei
/// Time   : Jun-10-2019

#include <iostream>

using namespace std;

#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
#include <utility>

using namespace std;


/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/// Recursive
/// Time Complexity: O(n), where n is the number of nodes in the tree
/// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        this->treeLevels = depth( root);
        vector< vector<int> > res( treeLevels, vector<int>());
        zigzagLevelOrder( root, res, 0);
        for( int i=0; i<res.size(); ++i)
            if( i % 2 == 1)
                reverse( res[i].begin(), res[i].end());

        return res;
    }
private:
    int treeLevels = 0;

    int depth( TreeNode* node) {

        if( !node) return 0;
        return 1 + max( depth( node->left), depth( node->right));
    }

    void zigzagLevelOrder( TreeNode* node, vector< vector<int> >& res, int level) {

        if( !node) return;
        res[ level].push_back( node->val);
        zigzagLevelOrder( node->left, res, level + 1);
        zigzagLevelOrder( node->right, res, level + 1);
    }
};


int main() {

    return 0;
}
