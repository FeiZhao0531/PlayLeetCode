/// Source : https://leetcode.com/problems/minimum-size-subarray-sum/description/
/// Author : Fei
/// Time   : May-11-2019

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// Time Complexity: O( n)
// Space Complexity: O( 1)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {

        int l = 0, r = -1; // nums[l,r]
        int sum = 0, res = INT_MAX;
        int n = nums.size();
        while( true) {
            if( sum >= s) {
                res = min( res, r - l + 1);
                sum -= nums[l];
                l ++;
            }
            else { // sum < s
                if( r + 1 < nums.size()) {
                    r ++;
                    sum += nums[r];
                }
                else
                    break;
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};

int main() {

    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    int s1 = 7;
    cout << Solution().minSubArrayLen(s1, nums1) << endl;

    return 0;
}
