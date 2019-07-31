/// Source : https://leetcode.com/problems/target-sum/
/// Author : Fei
/// Time   : Jul-28-2019

#include <iostream>
#include <vector>

using namespace std;


/// Backtracking
/// Time Complexity: O(2^n)
/// Space Complexity: O(n)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {

        int sum = 0;
        for( int n : nums)
            sum += n;
        if( abs(sum) < abs(S))
            return 0;

        return dfs( nums, nums.size() - 1 , S);
    }

private:
    int dfs( const vector<int>& nums, int p, int S) {

        if( p == -1)
            return S == 0;

        return ( dfs( nums, p - 1, S + nums[p]) + dfs( nums, p - 1, S - nums[p]));
    }
};


int main() {

    vector<int> nums = {1, 1, 1, 1, 1};
    cout << Solution().findTargetSumWays(nums, 3) << endl;

    return 0;
}
