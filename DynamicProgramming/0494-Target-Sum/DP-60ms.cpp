/// Source : https://leetcode.com/problems/target-sum/description/
/// Author : Fei
/// Time   : Jul-28-2019

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Dynamic Programming
/// States space compression
///
/// Time Complexity: O(n * maxNum)
/// Space Complexity: O(maxNum)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {

        if( nums.size() == 0)
            return 0;
        if( 1000 + S > 2000 || 1000 + S < 0)
            return 0;

        vector<int> memo( 2001, 0);
        memo[1000 + nums[0]] ++; /// could not be " memo[1000 + nums[0]] = 1,
        memo[1000 - nums[0]] ++; /// because for the case nums[0] = 0, it's wrong

        for( int i = 1; i < nums.size(); ++i) {
            vector<int> tmp( 2001, 0);
            for( int j = 0; j < 2001; ++j) {
                if( j - nums[i] >= 0 && j - nums[i] < 2001)
                    tmp[j] += memo[j - nums[i]];
                if( j + nums[i] >= 0 && j + nums[i] < 2001)
                    tmp[j] += memo[j + nums[i]];
            }
            memo = tmp;
        }

        return memo[1000 + S];
    }
};
int main() {

    vector<int> nums = { 0,0,0,0,0,0,0,1000};
    cout << Solution().findTargetSumWays(nums, -1000) << endl;

    return 0;
}
