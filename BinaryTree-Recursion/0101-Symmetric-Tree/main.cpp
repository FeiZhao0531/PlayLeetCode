/// Source : https://leetcode.com/problems/symmetric-tree/description/
/// Author : Fei
/// Time   : Jun-19-2019

#include <iostream>
#include <vector>
#include <string>
#include "../BinaryTree.cpp"
#include "../BinaryTree.h"

using namespace std;

/// Recursive
/// Time Complexity: O(n)
/// Space Complexity: O(h)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        if( !root)
            return true;
        return _helper( root->left, root->right);
    }
private:
    bool _helper( TreeNode* p, TreeNode* q) {

        if( !p && !q)
            return true;
        if( !p || !q || p->val != q->val)
            return false;

        return  _helper( p->left, q->right) && _helper( p->right, q->left);
    }
};

int main() {

    vector<int> preVec{ 1, 2, 3, 2, 3};
    vector<int> inVec{ 2, 3, 1, 2, 3};
    BinaryTree binTree( preVec, inVec);
    TreeNode* root = binTree.getRootNode();
    cout<< Solution().isSymmetric( root) ? "true" : "false" << endl;
    return 0;
}
