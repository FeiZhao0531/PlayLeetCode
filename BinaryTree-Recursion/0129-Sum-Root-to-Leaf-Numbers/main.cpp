/// Source : https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
/// Author : Fei
/// Time   : Jun-21-2019

#include "../BinaryTree.cpp"
#include "../BinaryTree.h"
#include <iostream>

using namespace std;


/// Recursion
/// Time Complexity: O(n)
/// Space Complexity: O(logn)

class Solution {
public:
    int sumNumbers(TreeNode* root) {

        int sum = 0, pathSum = 0;
        dfs( root, sum, pathSum);

        return sum;
    }
private:
    void dfs( TreeNode* node, int& sum, int pathSum) {

        if( !node)
            return;
        int newPathSum = 10 * pathSum + node->val;
        if( !node->left && !node->right) {
            sum += newPathSum;
            return;
        }

        dfs( node->left, sum, newPathSum);
        dfs( node->right, sum, newPathSum);
    }
};


int main() {

    vector<int> preOrderVec { 5, 4, 1, 7, 2, 8, 3, 4, 5, 1};
    vector<int> inOrderVec { 7, 1, 2, 4, 5, 3, 8, 5, 4, 1};
    BinaryTree binTree( preOrderVec, inOrderVec) ;
    TreeNode* root = binTree.getRootNode();
    cout << "sum Numbers = " << Solution().sumNumbers( root) << endl;

    return 0;
}
