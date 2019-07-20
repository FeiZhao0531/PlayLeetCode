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
        memo = vector<int>( 1 + n, INT_MAX); // memo[i] : result of numSquares(i)
        return memorySearch( n);
    }

private:
    vector<int> memo;

    int memorySearch( int n) {

        if( n <= 3)
            return n;

        for( int i=1; i*i <= n; ++i) {
            int rest = n - i * i;
            if( memo[rest] == INT_MAX) memo[rest] = memorySearch( rest);
            memo[n] = min( memo[n], memo[rest] + 1);
        }

        return memo[n];
    }
};;

int main() {

    cout << Solution().numSquares(5) << endl;

    return 0;
}
