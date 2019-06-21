/// Source : https://leetcode.com/problems/minimum-depth-of-binary-tree/
/// Author : Fei
/// Time   : Jun-19-2019

#include "../BinaryTree.cpp"
#include "../BinaryTree.h"
#include <iostream>

using namespace std;

/// Recursive
/// Time Complexity: O(n)
/// Space Complexity: O(h)
class Solution {
public:
    int minDepth(TreeNode* root) {

        if( !root)
            return 0;
        if( root->left == NULL && root->right == NULL)
            return 1;
        int res = INT_MAX;
        if( root->left)
            res = min( res, minDepth( root->left));
        if( root->right)
            res = min( res, minDepth( root->right));

        return 1 + res;
    }
};


int main() {

    vector<int> preOrderVec { 3, 9, 20, 15, 7};
    vector<int> inOrderVec { 9, 3, 15, 20 ,7};
    BinaryTree binTree( preOrderVec, inOrderVec) ;
    TreeNode* root = binTree.getRootNode();

    cout<< " Min depth of this binary Tree: " << Solution().minDepth( root) << endl;
    return 0;
}
