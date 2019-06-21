/// Source : https://leetcode.com/problems/balanced-binary-tree/
/// Author : Fei
/// Time   : Jun-20-2019

#include "../BinaryTree.cpp"
#include "../BinaryTree.h"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

/// Recursive , update of the 1st solution
/// if sub-tree is unbalanced, no need to check the upper node
/// Time Complexity: O(n)
/// Space Complexity: O(h)
class Solution {
public:
    bool isBalanced( TreeNode*root) {

        if( !root)
            return true;
        return _height( root) != -1;
    }
private:
    int _height( TreeNode* node) {

        if( !node)
            return 0;
        int lHeight = _height( node->left);
        int rHeight = _height( node->right);
        if( lHeight == -1 || rHeight == -1)
            return -1;

        if( abs( lHeight - rHeight) > 1)
            return -1;

        return 1 + max( _height( node->left), _height( node->right));
    }
};

int main() {

    vector<int> preVec{ 1, 2, 3, 4, 4, 3, 2};
    vector<int> inVec{ 4, 3, 4, 2, 3, 1, 2};
    BinaryTree binTree( preVec, inVec);
    TreeNode* root = binTree.getRootNode();
    string s = Solution().isBalanced( root) ? "true" : "false";
    cout<< s << endl;
    return 0;
}
