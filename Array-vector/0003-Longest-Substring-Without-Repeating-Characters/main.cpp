/// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
/// Author : Fei
/// Time   : May-12-2019

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

/// Sliding Window
/// Time Complexity: O(len(s))
/// Space Complexity: O(len(charset))
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if( s.size() == 0)
            return 0;
        vector<int> record( 256, 0);
        int l = 0, r = 0; // [l,r]
        int res = 0;
        while( r < s.size()) {
            if( record[ s[r]] == 0) {
                record[ s[r]] ++;
                res = max( res, r - l + 1);
                r ++;
            }
            else { // record[ s[r]] == 1
                while( s[l] != s[r]) {
                    record[ s[l]] --;
                    l ++;
                }
                record[ s[l]] --;
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
