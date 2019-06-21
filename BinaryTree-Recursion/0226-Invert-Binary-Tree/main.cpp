/// Source : https://leetcode.com/problems/invert-binary-tree/description/
/// Author : Fei
/// Time   : Jun-19-2019

#include <iostream>
#include <vector>
#include "../BinaryTree.cpp"
#include "../BinaryTree.h"

using namespace std;

/// Recursive
/// Time Complexity: O(n), where n is the node's number of the tree
/// Space Complexity: O(h), where h is the height of the tree
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if( !root)
            return NULL;

        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);

        return root;
    }
};

int main() {

    vector<int> preVec{ 4, 2, 1, 3, 7, 6, 9};
    vector<int> inVec{ 1, 2, 3, 4, 6, 7, 9};
    BinaryTree binTree( preVec, inVec);
    TreeNode* root = binTree.getRootNode();
    binTree.levelOrderPrint( root);

    binTree.levelOrderPrint( Solution().invertTree( root));
    return 0;
}
