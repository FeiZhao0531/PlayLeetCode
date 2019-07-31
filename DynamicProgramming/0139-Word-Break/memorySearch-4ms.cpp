/// Source : https://leetcode.com/problems/word-break/
/// Author : Fei
/// Time   : Jul-31-2019

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Memory Search
/// Think clearly the meaning of recursion function
///
/// Time Complexity: O(n ^ 2)
/// Space Complexity: O(n)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> unSet( wordDict.begin(), wordDict.end());
        maxWordLength = getMaxWordLength( wordDict);
        memo = vector<int>( s.size(), -1);

        return memorySearch( s, unSet, 0);
    }
private:
    int maxWordLength = 0;
    vector<int> memo;

    bool memorySearch( const string& s, const unordered_set<string>& unSet, int p) {

        if( p == s.size())
            return true;
        if( memo[p] != -1)
            return memo[p];

        for( int i = p; i < s.size() && i - p < maxWordLength; ++i) { /// no need to iterate all the sub-string start from s[p]
            if( unSet.find( s.substr( p, i - p + 1)) != unSet.end()
                    && memorySearch( s, unSet, i + 1))
                return memo[p] = true;
        }

        return memo[p] = false;
    }

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
