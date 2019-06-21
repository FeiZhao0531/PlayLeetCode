/// Source : https://leetcode.com/problems/sum-of-left-leaves/
/// Author : Fei
/// Time   : Jun-20-2019

#include "../BinaryTree.cpp"
#include "../BinaryTree.h"
#include <iostream>

using namespace std;


/// BFS
/// Time Complexity: O(n)
/// Space Complexity: O(h)

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {

        if( !root)
            return 0;
        int res = 0;
        queue< TreeNode*> q;
        q.push( root);
        while( !q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if( node->left && !node->left->left && !node->left->right)
                res += node->left->val;
            if( node->left)
                q.push( node->left);
            if( node->right)
                q.push( node->right);
        }

        return res;
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
