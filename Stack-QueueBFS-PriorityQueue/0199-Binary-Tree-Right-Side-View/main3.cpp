/// Source : https://leetcode.com/problems/binary-tree-right-side-view/
/// Author : Fei
/// Time   : Jun-11-2019

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

/// BFS
/// Time Complexity: O(n), where n is the number of nodes in the tree
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        vector<int> res;
        rightSideView( root, res, 1);
        return res;
    }

private:
    void rightSideView( TreeNode* node, vector<int>& res, int level) {

        if( !node) return;
        if( res.size() < level)
            res.push_back( node->val);
        rightSideView( node->right, res, level + 1);
        rightSideView( node->left, res, level + 1);
    }
};


int main() {

    return 0;
}
