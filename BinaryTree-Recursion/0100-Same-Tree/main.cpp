/// Source : https://leetcode.com/problems/same-tree/description/
/// Author : Fei
/// Time   : Jun-19-2019

#include <iostream>
#include "../BinaryTree.cpp"
#include "../BinaryTree.h"

using namespace std;

/// Recursion
/// Time Complexity: O(n)
/// Space Complexity: O(h)

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if( !p && !q)
            return true;
        if( ( p && !q) || ( !p && q) || ( p && q && p->val != q->val))
            return false;

        return isSameTree( p->left, q->left) && isSameTree( p->right, q->right);
    }
};


int main() {

    return 0;
}
