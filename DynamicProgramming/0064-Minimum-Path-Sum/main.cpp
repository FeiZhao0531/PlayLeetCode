/// Source : https://leetcode.com/problems/minimum-path-sum/description/
/// Author : Fei
/// Time   : Jul-18-2019

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Dynamic Programming
/// with O(n) space, just n space.
///
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        assert( m > 0);
        int n = grid[0].size();
        assert( n > 0);

        vector<int> memo = grid[0];
        for( int j=1; j<n; ++j)
            memo[j] += memo[j-1];

        for( int i=1; i<m; ++i) {
            for( int j=0; j<n; ++j) {
                if( j == 0)
                    memo[j] += grid[i][j];
                else
                    memo[j] = grid[i][j] + min( memo[j-1], memo[j]);
            }
        }

        return memo[n-1];
    }
};

int main() {

    vector<vector<int>> grid = {{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}};
    cout << Solution().minPathSum(grid) << endl;

    return 0;
}
