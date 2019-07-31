/// Source : https://leetcode.com/problems/word-break/
/// Author : Fei
/// Time   : Jul-31-2019

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Dynamic Programming method #1
///
/// Time Complexity: O(n ^ 2)
/// Space Complexity: O(n)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> unSet( wordDict.begin(), wordDict.end());
        int maxWordLength = getMaxWordLength( wordDict);
        vector<bool> memo( 1 + s.size(), false);
        memo[0] = true;

        for( int i = 0; i < s.size(); ++ i) {
            if( !memo[i]) continue;
            for( int j = i; j < s.size() && j - i < maxWordLength; ++ j) {
                if( unSet.find( s.substr( i, j - i + 1)) != unSet.end())
                    memo[j + 1] = true;
            }
            if( memo[s.size()])
                return true;
        }

        return false;
    }
private:
    int getMaxWordLength( const vector<string>& wordDict) {

        int res = 0;
        for( string s : wordDict)
            res = max( res, (int)s.size());

        return res;
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
