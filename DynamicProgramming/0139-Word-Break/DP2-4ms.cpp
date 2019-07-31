/// Source : https://leetcode.com/problems/word-break/
/// Author : Fei
/// Time   : Jul-31-2019

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Dynamic Programming method #2
///
/// Time Complexity: O(n ^ 2)
/// Space Complexity: O(n)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> unSet( wordDict.begin(), wordDict.end());
        vector<bool> memo( 1 + s.size(), false);
        memo[0] = true;

        for( int i = 1; i <= s.size(); ++ i) {
            for( int j = i - 1; j >= 0; -- j) {
                if( memo[j] && unSet.find( s.substr( j, i - j)) != unSet.end()) {
                    memo[i] = true;
                    break;
                }
            }
        }

        return memo.back();
    }
};

void printBool( bool TF) {
    if( TF)
        cout << "Ture" << endl;
    else
        cout << "False" << endl;
}

int main() {

    string s = "goalspecial";
    vector<string> wordDict = { "go","goal","goals","special"};
    Solution s1;
    printBool( s1.wordBreak( s, wordDict));

    return 0;
}
