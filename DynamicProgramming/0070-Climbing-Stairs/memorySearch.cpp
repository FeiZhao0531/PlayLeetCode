/// Source : https://leetcode.com/problems/climbing-stairs/description/
/// Author : Fei
/// Time   : Jul-17-2019

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Memory Search
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int climbStairs(int n) {

        memo = vector<int>( n + 1, -1);
        int res = _helper( n);

        return res;
    }
private:
    vector<int> memo;

    int _helper( int n) {

        if( n == 1 || n == 2)
            return n;

        if( memo[n] == -1)
            memo[n] = _helper( n - 1) + _helper( n - 2);

        return memo[n];
    }
};

int main() {

    cout << Solution().climbStairs(10) << endl;

    return 0;
}
