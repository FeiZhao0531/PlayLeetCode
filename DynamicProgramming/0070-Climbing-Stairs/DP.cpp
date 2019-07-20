/// Source : https://leetcode.com/problems/climbing-stairs/description/
/// Author : Fei
/// Time   : Jul-17-2019

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Dynamic Programming
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int climbStairs(int n) {

        if( n == 1 || n == 2)
            return n;

        vector<int> memo( n + 1, -1);
        memo[1] = 1;memo[2] = 2;
        for( int i=3; i<=n; ++i)
            memo[i] = memo[i-1] + memo[i-2];

        return memo[n];
    }
};

int main() {

    cout << Solution().climbStairs(10) << endl;
    return 0;
}
