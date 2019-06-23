/// Source : https://leetcode.com/problems/delete-node-in-a-bst/
/// Author : Fei
/// Time   : Jun-23-2019

#include "../BinaryTree.cpp"
#include "../BinaryTree.h"
#include <iostream>
#include <vector>

using namespace std;

/// Time Complexity: O(h) h-height of this BST tree
/// Space Complexity: O(h)
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        if( !root)
            return NULL;

        if( root->val > key)
            root->left = deleteNode( root->left, key);
        else if( root->val < key)
            root->right = deleteNode( root->right, key);
        else { // root->val == key
            if( !root->right) {
                TreeNode* lNode = root->left;
                delete root;
                root = NULL;
                return lNode;
            }
            else if( !root->left) {
                TreeNode* rNode = root->right;
                delete root;
                root = NULL;
                return rNode;
            }
            else {
                TreeNode* tmp = root->left;
                while( tmp->right)
                    tmp = tmp->right;
                root->val = tmp->val;
                root->left = deleteNode( root->left, root->val);
                //tmp = NULL;
            }
        }

        return root;
    }
};


int main() {

    vector<int> preVec{ 5, 3, 2, 4, 6, 7};
    vector<int> inVec{ 2, 3, 4, 5, 6, 7};
    BinaryTree binTree( preVec, inVec);
    TreeNode* root = binTree.getRootNode();
    binTree.levelOrderPrint( Solution().deleteNode( root, 5));

    return 0;
}
