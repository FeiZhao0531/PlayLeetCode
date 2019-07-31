/// Source : https://leetcode.com/problems/combination-sum-iv/
/// Author : Fei
/// Time   : Jul-25-2019

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Memory Search
/// Compared to the Naive Backtracking, no need to sort the vector at first
/// Time Complexity: O(n * target)
/// Space Complexity: O(n * target)
class Solution {

private:
    vector<int> dp;

public:
    int combinationSum4(vector<int>& nums, int target) {

        if( nums.size() == 0)
            return 0;

        dp = vector<int>( target + 1, -1);
        dp[0] = 1;

        memorySearch( nums, target);
        //cout << counter << endl;
        return dp[target];
    }

private:
    //int counter = 0;

    int memorySearch(const vector<int>& nums, int target){

        //counter ++;
        if( dp[target] != -1)
            return dp[target];

        int res = 0;
        for(int i = 0; i < nums.size() ; i ++)
            if( target >= nums[i])
                res += memorySearch( nums, target - nums[i]);

        return dp[target] = res;
    }
};


int main() {

    vector<int> nums1 = { 2, 1, 3};
    int target1 = 32;
    cout << Solution().combinationSum4(nums1, target1) << endl;

    return 0;
}
