/// Source : https://leetcode.com/problems/unique-paths/
/// Author : Fei
/// Time   : Jul-19-2019

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(m * n)
/// Space Complexity: O(m)
class Solution {
public:
    int uniquePaths(int m, int n) {

        if( m == 0 || n == 0)
            return 0;

        vector<int> memo( n, 1);
        for( int i=1; i<m; ++i)
            for( int j=1; j<n; ++j)
                memo[j] += memo[j-1];

        return memo[n-1];
    }
};


int main() {

    cout << Solution().uniquePaths( 3, 7) << endl;
    return 0;
}
