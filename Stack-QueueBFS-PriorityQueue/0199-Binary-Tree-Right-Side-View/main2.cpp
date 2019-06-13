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
		if (!root)
            return res;
		queue< TreeNode*> q;
		q.push( root);
		while ( !q.empty()) {
			res.push_back( q.front()->val);
			int sz = q.size();
			for ( int i = 0; i < sz; ++i) {
				TreeNode* node = q.front();
				q.pop();
				if ( node->right)
                    q.push(node->right);
				if ( node->left)
                    q.push(node->left);
			}
		}

		return res;
    }
};


int main() {

    return 0;
}
