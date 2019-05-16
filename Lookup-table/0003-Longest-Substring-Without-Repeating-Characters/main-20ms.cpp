/// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
/// Author : Fei
/// Time   : May-14-2019

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <unordered_set>
using namespace std;

/// Sliding Window and unordered_set
/// Time Complexity: O(len(s) * log(len(s)))
/// Space Complexity: O(len(charset))
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> unSet;
        int res = 0;
        int l = 0, r = 0; // [l,r] to contain the longest substring
        while( r < s.size()) {
            if( unSet.find( s[r]) == unSet.end()) {
                unSet.insert( s[r]);
                res = max( res, r - l + 1);
                r ++;
            }
            else {
                unSet.erase( s[l]);
                l ++;
            }
        }

        return res;
    }
};

int main() {

    cout << Solution().lengthOfLongestSubstring( "abcabcbb" )<<endl; //3
    cout << Solution().lengthOfLongestSubstring( "bbbbb" )<<endl;    //1
    cout << Solution().lengthOfLongestSubstring( "pwwkew" )<<endl;   //3
    cout << Solution().lengthOfLongestSubstring( "c" )<<endl;        //1
    cout << Solution().lengthOfLongestSubstring( "" )<<endl;         //0

    return 0;
}
