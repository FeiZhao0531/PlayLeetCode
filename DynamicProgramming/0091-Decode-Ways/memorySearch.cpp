/// Source : https://leetcode.com/problems/decode-ways/
/// Author : Fei
/// Time   : Jul-19-2019

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
        memo = vector<int>( 1 + n, -1); // memo[i] == -1 : not calculate
        memo[n] = 1;

        return memorySearch( 0, s);
    }
private:
    vector<int> memo;

    int memorySearch( int p, string& s) {

        if( memo[p] != -1) return memo[p];
        if( s[p] == '0') return memo[p] = 0;

        memo[p] = memorySearch( p + 1, s);
        if( p < s.size() - 1 && ( s[p] == '1' || s[p] == '2' && s[p+1] <= '6'))
            memo[p] += memorySearch( p + 2, s);

        return memo[p];
    }
};


int main() {

    string s = "226";
    cout << Solution().numDecodings( s) << endl;
    return 0;
}
