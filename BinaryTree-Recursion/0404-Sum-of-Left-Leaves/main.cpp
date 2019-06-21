/// Source : https://leetcode.com/problems/sum-of-left-leaves/
/// Author : Fei
/// Time   : Jun-20-2019

#include "../BinaryTree.cpp"
#include "../BinaryTree.h"
#include <iostream>

using namespace std;


/// Recursive
/// Time Complexity: O(n)
/// Space Complexity: O(h)

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {

        if( !root)
            return 0;

        if( root->left && !root->left->left && !root->left->right)
            return root->left->val + sumOfLaftLeaves( root->right);

        return sumOfLeftLeaves( root->left) + sumOfLeftLeaves( root->right);
    }
};


int main() {

    vector<int> preOrderVec { 3, 9, 20, 15, 7};
    vector<int> inOrderVec { 9, 3, 15, 20 ,7};
    BinaryTree binTree( preOrderVec, inOrderVec) ;
    TreeNode* root = binTree.getRootNode();

    cout<< " sumOfLeftLeaves: " << Solution().sumOfLeftLeaves( root) << endl;
    return 0;
}
