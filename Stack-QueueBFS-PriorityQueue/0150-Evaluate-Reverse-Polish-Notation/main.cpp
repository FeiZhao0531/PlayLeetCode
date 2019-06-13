/// Source : https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
/// Author : Fei
/// Time   : Jun-09-2019

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> stk;
        for(const string& s: tokens){
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();

                switch( *(s.c_str()) ) {
                    case '+':
                        stk.push( b + a);
                        break;
                    case '-':
                        stk.push( b - a);
                        break;
                    case '*':
                        stk.push( b * a);
                        break;
                    case '/':
                        stk.push( b / a);
                        break;
                    default:
                        return false;
                }
            }
            else
                stk.push( stoi(s));
        }
        return stk.top();
    }
};


int main() {

    return 0;
}
