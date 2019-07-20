/// Source : https://leetcode.com/problems/triangle/description/
/// Author : Fei
/// Time   : Jul-17-2019

#include <iostream>
#include <vector>

using namespace std;

/// Dynamic Programming
/// From bottom to top
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        assert( n > 0);

        vector<int> memo = triangle.back();
        for( int i=n-2; i>=0; --i)
            for( int j=0; j<=i; ++j)
                memo[j] = triangle[i][j] + min( memo[j], memo[j+1]);

        return memo[0];
    }
};


int main() {

    vector<vector<int>> triangle = { {2},
                                     {3,4},
                                     {6,5,7},
                                     {4,1,8,3}};
    cout << Solution().minimumTotal(triangle) << endl;
    // 11

    return 0;
}
