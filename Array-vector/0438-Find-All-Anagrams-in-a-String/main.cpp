/// Source : https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
/// Author : Fei
/// Time   : May-12-2019

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

/// Sliding Window
/// Time Complexity: O(len(p) + len(s))
/// Space Complexity: O(1)

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> res;
        if( s.size() < p.size())
            return res;

        vector<int> pVec(26,0), sVec(26,0);
        for( int i=0; i<p.size(); ++i) {
            pVec[ p[i] - 'a'] ++;
            sVec[ s[i] - 'a'] ++;
        }
        for( int i=p.size(); i<s.size(); ++i) {
            if( pVec == sVec)
                res.push_back( i - p.size());
            sVec[ s[i-p.size()] - 'a'] --;
            sVec[ s[i] - 'a'] ++;
        }
        if( sVec == pVec)
            res.push_back( s.size() - p.size());

        return res;
    }
};

void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    string s1 = "cbaebabacd";
    string p1 = "abc";
    printVec(Solution().findAnagrams(s1, p1));
    // [0, 6]

    // ---

    string s2 = "abab";
    string p2 = "ab";
    printVec(Solution().findAnagrams(s2, p2));

    return 0;
}
