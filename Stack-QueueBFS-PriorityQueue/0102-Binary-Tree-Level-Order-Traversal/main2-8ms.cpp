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

/// BFS
/// Time Complexity: O(n), where n is the number of nodes in the tree
/// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector< vector<int> > res;
        if( !root)
            return res;
        queue< nodeLevel> q;
        q.push( nodeLevel( root, 0));
        while( !q.empty()) {
            TreeNode* curNode = q.front().node;
            int curLevel = q.front().level;
            q.pop();
            if( curLevel == res.size())
                res.push_back( vector<int>());
            res[ curLevel].push_back( curNode->val);
            if( curNode->left)
                q.push( nodeLevel( curNode->left, curLevel + 1));
            if( curNode->right)
                q.push( nodeLevel( curNode->right, curLevel + 1));
        }

        return res;
    }
private:
    struct nodeLevel {
        TreeNode* node;
        int level;
        nodeLevel( TreeNode* node, int level) {
            this->node = node;
            this->level = level;
        }
    };
};


int main() {

    return 0;
}
