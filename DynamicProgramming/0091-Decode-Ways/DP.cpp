/// Source : https://leetcode.com/problems/decode-ways/
/// Author : Fei
/// Time   : Jul-20-2019

#include <iostream>
#include <vector>

using namespace std;


/// memory search
/// Time Complexity: O( s.size())
/// Space Complexity: O( s.size())
class Solution {
public:
    int numDecodings(string s) {

        int n = s.size();
        if( n == 0) return 0;
        vector<int> memo( 1 + n, 0); // memo[i] == -1 : not calculate
        memo[n] = 1;
        for( int i=n-1; i>=0; --i) {
            if( s[i] == '0') continue;
            memo[i] = memo[i+1];
            if( i <= n-2 && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6'))
                memo[i] += memo[i+2];
        }

        return memo[0];
    }
};


int main() {

    string s = "226";
    cout << Solution().numDecodings( s) << endl;
    return 0;
}
