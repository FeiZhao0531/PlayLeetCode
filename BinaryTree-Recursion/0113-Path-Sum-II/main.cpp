/// Source : https://leetcode.com/problems/path-sum-ii/description/
/// Author : Fei
/// Time   : Jun-20-2019

#include "../BinaryTree.cpp"
#include "../BinaryTree.h"
#include <iostream>
#include <vector>

using namespace std;


/// Recursion
/// Time Complexity: O(n)
/// Space Complexity: O(n)

class Solution {
public:
    vector< vector<int> > pathSum(TreeNode* root, int sum) {

        vector<int> path;
        dfs( root, sum, path);

        return res;
    }
private:
    vector< vector<int> > res;

    void dfs( TreeNode* node, int restSum, vector<int>& path) {

        if( !node)
            return;

        path.push_back( node->val);
        if( !node->left && !node->right && node->val == restSum)
            res.push_back( path);
        dfs( node->left, restSum - node->val, path);
        dfs( node->right, restSum - node->val, path);

        path.pop_back();
    }
};

void print2DVec( const vector< vector<int> >& res) {

    for( auto iter=res.begin(); iter != res.end(); ++iter) {
        for( int a : *iter)
            cout<< a << "  ";
        cout << endl;
    }
    cout <<endl;
}


int main() {

    vector<int> preOrderVec { 5, 4, 11, 7, 2, 8, 13, 4, 5, 1};
    vector<int> inOrderVec { 7, 11, 2, 4, 5, 13, 8, 5, 4, 1};
    BinaryTree binTree( preOrderVec, inOrderVec) ;
    TreeNode* root = binTree.getRootNode();
    vector< vector<int> > res = Solution().pathSum( root, 22);
    print2DVec( res);

    return 0;
}
