/// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
/// Author : Fei
/// Time   : May-14-2019

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <unordered_map>
using namespace std;

/// Sliding Window and unordered_map
/// Time Complexity: O(len(s)*log( len(s)) )
/// Space Complexity: O(len(charset))
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> unMap; // < char, int > : < s[i], index>
        int res = 0;
        int l = 0, r = 0; // [ l, r]
        while( r < s.size()) {
            if( unMap.count(s[ r]) != 0)
                l = max( l, unMap[ s[r]] + 1);

            unMap[ s[r]] = r;
            res = max( res, r - l + 1);
            r ++;
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
