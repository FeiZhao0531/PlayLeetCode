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

        int currMax = 0, prevMax = 0;
        for( int i=0; i<n; ++i) {
            int temp = currMax;
            currMax = max( currMax, nums[i] + prevMax);
            prevMax = temp;
        }

        return currMax;
    }
};

int main() {

    int nums[] = {2,7,9,3,1};
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int));

    cout << Solution().rob(vec) << endl;

    return 0;
}
