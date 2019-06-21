/// Source : https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
/// Author : Fei
/// Time   : Jun-17-2019

#include "../BinaryTree.cpp"
#include "../BinaryTree.h"
#include <iostream>
#include <stack>

using namespace std;

/// Non-recursive
/// Time Complexity: O(n), where n is the nodes' number in the tree
/// Space Complexity: O(h), where h is the height of the tree
class Solution {
public:
    int maxDepth(TreeNode* root) {

        if( !root)
            return 0;
        int res = 0;
        stack< pair< TreeNode*, int> > stk;
        stk.push( make_pair( root, 1));
        while( !stk.empty()) {
            TreeNode* node = stk.top().first;
            int depth = stk.top().second;
            stk.pop();
            if( node->left == NULL && node->right == NULL)
                res = max( res, depth);
            else {
                if( node->left)
                    stk.push( make_pair( node->left, depth + 1));
                if( node->right)
                    stk.push( make_pair( node->right, depth + 1));
            }
        }

        return res;
    }
};

int main() {

    vector<int> preOrderVec { 3, 9, 20, 15, 7};
    vector<int> inOrderVec { 9, 3, 15, 20 ,7};
    BinaryTree binTree( preOrderVec, inOrderVec) ;
    TreeNode* root = binTree.getRootNode();
    cout<<" root->val = " << root->val << endl;

    cout<< " Max depth of this binary Tree: " << Solution().maxDepth( root) << endl;
    return 0;
}
