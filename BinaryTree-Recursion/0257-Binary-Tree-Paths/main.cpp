/// Source : https://leetcode.com/problems/binary-tree-paths/description/
/// Author : Fei
/// Time   : Jun-21-2019

#include "../BinaryTree.cpp"
#include "../BinaryTree.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/// Recursive
/// Time Complexity: O(n), where n is the node's number in the tree
/// Space Complexity: O(h), where h is the height of the tree
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> res;
        if( !root)
            return res;
        string s;
        _path( root, s, res);

        return res;
    }
private:
    void _path( TreeNode* node, string s, vector<string>& res) {

        if( !node)
            return;
        s += to_string( node->val);
        if( !node->left && !node->right) {
            res.push_back( s);
            return;
        }

        s += "->";
        _path( node->left, s, res);
        _path( node->right, s, res);
    }
};

void printVec( vector<string>& vec) {

    for( string s : vec)
        cout<< s << endl;
}

int main() {

    vector<int> preOrderVec { 5, 4, 11, 7, 2, 8, 13, 4, 5, 1};
    vector<int> inOrderVec { 7, 11, 2, 4, 5, 13, 8, 5, 4, 1};
    BinaryTree binTree( preOrderVec, inOrderVec) ;
    TreeNode* root = binTree.getRootNode();
    vector<string> res = Solution().binaryTreePaths( root);
    printVec( res);
    return 0;
}
