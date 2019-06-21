/// Source : https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
/// Author : Fei
/// Time   : Jun-17-2019

#include "../BinaryTree.cpp"
#include "../BinaryTree.h"
#include <iostream>
#include <algorithm>

using namespace std;

/// Recursive
/// Time Complexity: O(n), where n is the nodes' number in the tree
/// Space Complexity: O(h), where h is the height of the tree
class Solution {
public:
    int maxDepth(TreeNode* root) {

        if( !root)
            return 0;

        return 1 + max( maxDepth(root->left), maxDepth( root->right));
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
