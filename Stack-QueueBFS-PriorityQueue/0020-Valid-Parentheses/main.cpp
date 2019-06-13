/// Source : https://leetcode.com/problems/valid-parentheses/description/
/// Author : Fei
/// Time   : Jun-09-2019

#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

// Using Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool isValid(string s) {

        stack<char> stk;
        for( int i=0; i<s.size(); ++i) {
            char e = s[i];
            if( e == '(' || e == '[' || e == '{')
                stk.push( e);
            else {
                if( stk.empty())
                    return false;
                else {
                    char match;
                    switch( e) {
                        case ')' :
                            match = '(';
                            break;
                        case ']' :
                            match = '[';
                            break;
                        case '}' :
                            match = '{';
                            break;
                        default:
                            return false;
                    }
                    if( stk.top() != match)
                        return false;
                    stk.pop();
                }
            }
        }
        if( stk.empty() == false)
            return false;

        return true;
    }
};


void printBool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    printBool(Solution().isValid("()"));
    printBool(Solution().isValid("()[]{}"));
    printBool(Solution().isValid("(]"));
    printBool(Solution().isValid("([)]"));

    return 0;
}
