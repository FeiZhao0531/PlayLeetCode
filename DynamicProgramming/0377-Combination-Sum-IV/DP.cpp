/// Source : https://leetcode.com/problems/combination-sum-iv/
/// Author : Fei
/// Time   : Jul-25-2019

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n * target)
/// Space Complexity: O(target)
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {

        int n = nums.size();
        if( n == 0)
            return 0;
        vector<unsigned int> dp( 1 + target, 0);
        dp[0] = 1;

        for( int i=1; i <= target; ++i) {
            for( int j=0; j<n; ++j)
                if( i >= nums[j])
                    dp[i] += dp[ i - nums[j]];
        }

        return dp[target];
    }
};


int main() {

    vector<int> nums1 = {1, 2, 3};
    int target1 = 32;
    cout << Solution().combinationSum4(nums1, target1) << endl;

    return 0;
}
