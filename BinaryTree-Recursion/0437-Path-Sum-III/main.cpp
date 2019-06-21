/// Source : https://leetcode.com/problems/path-sum-iii/description/
/// Author : Fei
/// Time   : Jun-20-2019
/// Time   : Jun-20-2019

#include "../BinaryTree.cpp"
#include "../BinaryTree.h"
#include <iostream>

using namespace std;

/// Recursive
/// Time Complexity: O(n), where n is the node's number of the tree
/// Space Complexity: O(h), where h is the height of the tree
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {

        if( !root)
            return 0;

        int counts = 0;
        pathFromRoot( root, sum, counts);

        return pathSum( root->left, sum) + pathSum( root->right, sum) + counts;
    }
private:
    void pathFromRoot( TreeNode* root, int sum, int& counts) {

        if( !root)
            return;
        if( root->val == sum)
            counts ++;

        pathFromRoot( root->left, sum - root->val, counts);
        pathFromRoot( root->right, sum - root->val, counts);
    }
};

int main() {

    /*****************
     * Test case:
     *
     *       10
     *      /  \
     *     5   -3
     *    / \    \
     *   3   2   11
     *  / \   \
     * 3  -2   1
     *****************/
    TreeNode* node1 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(-2);

    TreeNode* node3 = new TreeNode(3);
    node3->left = node1;
    node3->right = node2;

    TreeNode* node4 = new TreeNode(1);
    TreeNode* node5 = new TreeNode(2);
    node5->right = node4;

    TreeNode* node6 = new TreeNode(5);
    node6->left = node3;
    node6->right = node5;

    TreeNode* node7 = new TreeNode(11);
    TreeNode* node8 = new TreeNode(-3);
    node8->right = node7;

    TreeNode* node9 = new TreeNode(10);
    node9->left = node6;
    node9->right = node8;

    cout << Solution().pathSum(node9, 8) << endl;

    return 0;
}
