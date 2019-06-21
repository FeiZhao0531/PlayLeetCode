/// Source : https://leetcode.com/problems/path-sum/description/
/// Author : Fei
/// Time   : Jun-20-2019

#include <iostream>

using namespace std;

/// Recursive
/// Time Complexity: O(n), where n is the nodes' number of the tree
/// Space Complexity: O(h), where h is the height of the tree
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {

        return findPathSum( root, 0, sum);
    }
private:
    bool findPathSum( TreeNode* node, int pathSum, int sum) {

        if( node == NULL)
            return false;

        int newPathSum = pathSum + node->val;
        if( node->left == NULL && node->right == NULL)
            return newPathSum == sum;

        return findPathSum( node->left, newPathSum, sum) ||
            findPathSum( node->right, newPathSum, sum);
    }
};


int main() {

    return 0;
}
