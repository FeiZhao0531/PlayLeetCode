/// Source : https://leetcode.com/problems/binary-tree-inorder-traversal/
/// Author : Fei
/// Time   : Jun-09-2019

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// My Non-Recursive
// Learned from liuyubobobo
// Time Complexity: O(n), n is the node number in the tree
// Space Complexity: O(h), h is the height of the tree
class Solution {

private:
    struct Command{
        string s;   // go, print
        TreeNode* node;
        Command(string s, TreeNode* node): s(s), node(node){}
    };

public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> res;
        if( root == NULL )
            return res;

        stack<Command> stack;
        stack.push(Command("go", root));
        while( !stack.empty() ){
            Command command = stack.top();
            stack.pop();

            if(command.s == "print")
                res.push_back(command.node->val);
            else{
                assert(command.s == "go");
                if(command.node->right)
                    stack.push(Command("go",command.node->right));
                stack.push(Command("print", command.node));
                if(command.node->left)
                    stack.push(Command("go",command.node->left));
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
