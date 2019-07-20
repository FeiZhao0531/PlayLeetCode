/// Source : https://leetcode.com/problems/unique-paths-ii/
/// Author : Fei
/// Time   : Jul-19-2019

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(m*n)
/// Space Complexity: O(m*n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();  // Row numbers
        if( m == 0) return 0;
        int n = obstacleGrid[0].size(); // Col numbers
        if( n == 0) return 0;

        vector<long> memo( n, 0);
        memo[0] = 1;
        for( int i=0; i<m; ++i) {
            for( int j=0; j<n; ++j) {
                if( obstacleGrid[i][j] == 1)
                    memo[j] = 0;
                else {
                    assert( obstacleGrid[i][j] == 0);
                    if( j > 0)
                        memo[j] += memo[j-1];
                }
            }
        }

        return memo[n-1];
    }
};


int main() {

    return 0;
}
