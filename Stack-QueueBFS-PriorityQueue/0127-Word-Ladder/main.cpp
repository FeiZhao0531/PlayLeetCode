/// Source : https://leetcode.com/problems/word-ladder/description/
/// Author : Fei
/// Time   : Jun-13-2019

#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
#include <unordered_set>
#include <algorithm>

using namespace std;

/// BFS
/// Using set to store all the words and erase visited word eagerly.
/// Time Complexity: O(n*n)
/// Space Complexity: O(n)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        if( find( wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        unordered_set<string> unSet( wordList.begin(), wordList.end());
        queue< pair<string,int> > q; // < word in List, the depth till this word>
        q.push( make_pair( beginWord, 1));
        unSet.erase( beginWord);
        vector<string> visited;

        while( !q.empty() && !unSet.empty()) {
            string s = q.front().first;
            int depth = q.front().second;
            q.pop();
            visited.clear();
            auto iter = unSet.begin();
            for( ; iter != unSet.end(); ++iter) {
                if( stringDefference( s, *iter) == 1) {
                    if( *iter == endWord)
                        return depth + 1;
                    q.push( make_pair( *iter, depth + 1));
                    visited.push_back( *iter);
                    // unSet.erase( iter); // wrong to erase directly
                }
            }
            for( auto it = visited.begin();
                it != visited.end(); ++it)
                unSet.erase( *it);
        }

        return 0;
    }

private:
    int stringDefference( const string& s1, const string& s2) {

        assert( s1.size() == s2.size());
        assert( s1 != s2);
        int res = 0;
        for( int i=0; i<s1.size(); ++i) {
            if( s1[i] != s2[i])
                res ++;
        }

        return res;
    }
};
int main() {

    vector<string> vec1 = {"hot","dot","dog","lot","log","cog"};
    string beginWord1 = "hit";
    string endWord1 = "cog";
    cout << Solution().ladderLength(beginWord1, endWord1, vec1) << endl;
    // 5

    // ---

    vector<string> vec2 = {"a","b","c"};
    string beginWord2 = "a";
    string endWord2 = "c";
    cout << Solution().ladderLength(beginWord2, endWord2, vec2) << endl;
    // 2

    return 0;
}
