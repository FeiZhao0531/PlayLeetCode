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
/// Time Complexity: O(n*26*wordLength)
/// Space Complexity: O(n)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        if( find( wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        unordered_set<string> dict( wordList.begin(), wordList.end());
        queue< pair< string, int> > q;
        q.push(make_pair(beginWord, 1));
        dict.erase(beginWord);

        while( !q.empty() && !dict.empty()) {

            string str = q.front().first;
            int ladder = q.front().second;
            q.pop();

            for( int i=0; i<str.size(); ++i) {
                string tmpstr = str;
                for(int j=0; j<26; ++j) {
                    tmpstr[i] = 'a'+j;
                    if( dict.find(tmpstr) != dict.end()) {
                        if( tmpstr == endWord) return ladder+1;
                        q.push( make_pair(tmpstr, ladder+1));
                        dict.erase( tmpstr);
                    }
                }
            }
        }
        return 0;
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
