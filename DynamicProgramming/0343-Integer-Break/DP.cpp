/// Source : https://leetcode.com/problems/integer-break/description/
/// Author : Fei
/// Time   : Jul-18-2019

#include <iostream>
#include <vector>

using namespace std;

/// Dynamic Programming
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int integerBreak(int n) {

        assert( n >= 2);
        vector<int> memo( 1 + n, -1);
        memo[1] = memo[2] = 1;
        for( int i=3; i<=n; ++i) {
            for( int j=1; j<i; ++j)
                memo[i] = max3( memo[i], ( i - j)*memo[j], ( i - j)*j);
        }

        return memo[n];
    }

private:
    inline static int max3( int a, int b, int c) { return max( a, max( b, c));}
};

int main() {

    cout << Solution().integerBreak(2) << endl;
    cout << Solution().integerBreak(3) << endl;
    cout << Solution().integerBreak(4) << endl;
    cout << Solution().integerBreak(10) << endl;

    return 0;
}
