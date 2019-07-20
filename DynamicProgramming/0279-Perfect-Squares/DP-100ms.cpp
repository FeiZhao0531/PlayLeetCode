/// Source : https://leetcode.com/problems/perfect-squares/description/
/// Author : Fei
/// Time   : Jul-18-2019

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Memory Search
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int numSquares(int n) {

        assert( n > 0);
        vector<int> memo( 1 + n, INT_MAX);
        memo[0] = 0; memo[1] = 1;

        for( int i=1; i <= n; ++i)
            for( int j=1; j*j <= i; ++j)
                memo[i] = min( memo[i], memo[ i - j*j] + 1);

        return memo[n];
    }
};

int main() {

    cout << Solution().numSquares(5) << endl;

    return 0;
}
