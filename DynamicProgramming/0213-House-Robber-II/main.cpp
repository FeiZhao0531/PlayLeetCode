/// Source : https://leetcode.com/problems/house-robber-ii/description/
/// Author : Fei
/// Time   : Jul-22-2019

#include <iostream>
#include <vector>

using namespace std;

/// Dynamic Programming
/// Two Pass House Robber I Problem
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        if( n == 0) return 0;
        if( n == 1) return nums[0];

        return max( partRob( nums, true), partRob( nums, false));
    }

    int partRob( vector<int>& nums, bool isFromBeginning) {

        int start = 0, end = nums.size() - 1; // [ start, end)
        if( !isFromBeginning) {
            ++ start;
            ++ end;
        }

        int prevMax = 0, currMax = 0;
        for( int i=start; i<end; ++i) {
            int temp = currMax;
            currMax = max( currMax, nums[i] + prevMax);
            prevMax = temp;
        }

        return currMax;
    }
};

int main() {

    vector<int> nums = {2, 7, 9, 3, 1};
    cout << Solution().rob(nums) << endl;

    return 0;
}
