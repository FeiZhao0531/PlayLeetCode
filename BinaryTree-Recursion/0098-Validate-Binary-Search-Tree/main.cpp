/// Source : https://leetcode.com/problems/validate-binary-search-tree/description/
/// Author : Fei
/// Time   : Jun-22-2019

#include <iostream>
#include <vector>

using namespace std;


/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/// Using inOrder traverse
/// Store all elements in an vector
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool isValidBST(TreeNode* root) {

        if( !root)
            return true;
        vector<int> record;
        inorder( root, record);

        return isAscending( record);
    }
private:
    void inorder( TreeNode* node, vector<int>& record) {

        if( node) {
            inorder( node->left, record);
            record.push_back( node->val);
            inorder( node->right, record);
        }
    }

    bool isAscending( vector<int>& vec) {

        if( vec.size() == 0)
            return true;
        for( int i=1; i<vec.size(); ++i)
            if( vec[i] <= vec[i-1])
                return false;

        return true;
    }
};


int main() {

    return 0;
}
