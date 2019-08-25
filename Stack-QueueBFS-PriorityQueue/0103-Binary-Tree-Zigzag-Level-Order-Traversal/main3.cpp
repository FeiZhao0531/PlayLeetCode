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

/// BFS
/// Time Complexity: O(n), where n is the number of nodes in the tree
/// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector< vector<int>> res;
        if( !root)
            return res;

        queue< TreeNode*> q;
        q.push( root);
        bool odd = false; // the first layer num = 0
        while( !q.empty()) {
            int sz = q.size();
            vector<int> tmp( sz);
            for( int i=0; i<sz; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if( odd)
                    tmp[ sz - 1 - i] = node->val;
                else
                    tmp[ i] = node->val;

                if( node->left)
                    q.push( node->left);
                if( node->right)
                    q.push( node->right);
            }
            odd = !odd;
            res.push_back( tmp);
        }

        return res;
    }
};


int main() {

    return 0;
}
