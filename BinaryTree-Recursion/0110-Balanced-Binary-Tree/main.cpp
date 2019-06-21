/// Source : https://leetcode.com/problems/balanced-binary-tree/
/// Author : Fei
/// Time   : Jun-20-2019

#include "../BinaryTree.cpp"
#include "../BinaryTree.h"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

/// Recursive Top to Bottom, check the depth of every node
/// Time Complexity: O(nlogn) for worst case O(n^2)
/// Space Complexity: O(h)
class Solution {
public:
    bool isBalanced( TreeNode* root) {

        if( !root)
            return true;
        if( abs( _depth( root->left) - _depth( root->right)) > 1)
            return false;

        return isBalanced( root->left) && isBalanced( root->right);
    }
private:
    int _depth( TreeNode* node) {

        if( !node)
            return 0;

        return 1 + max( _depth( node->left), _depth( node->right));
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
