/// Source : https://leetcode.com/problems/house-robber/description/
/// Author : Fei
/// Time   : Jul-21-2019

#include <iostream>
#include <vector>

using namespace std;

/// DP
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        if( n == 0)
            return 0;

        vector<int> memo( n, -1);
        memo[0] = nums[0];
        for( int i=1; i<n; ++i)
            memo[i] = max( memo[i-1],
                           nums[i] + ( i == 1 ? 0 : memo[i-2]));

        return memo[n-1];
    }
};

int main() {

    int nums[] = {2,7,9,3,1};
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int));

    cout << Solution().rob(vec) << endl;

    return 0;
}
