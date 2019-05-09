///  source: https://leetcode.com/problems/kth-largest-element-in-an-array/
///  author: Fei Zhao
///  creating time: May-8-2019

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:

//  Time complexity: O( nlogn)
//  Space complexity: O( 1)
    int findKthLargest(vector<int>& nums, int k) {

        assert( k <= nums.size() && k >= 1);
        sort( nums.begin(), nums.end());
        return nums[ nums.size() - k];
    }
};

int main() {

    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    cout << Solution().findKthLargest(nums1, 2) << endl;
    // 5

    vector<int> nums2 = {3, 1, 2, 4};
    cout << Solution().findKthLargest(nums2, 2) << endl;
    // 3

    vector<int> nums3 = {3, 3, 3, 3, 3, 3, 3, 3, 3};
    cout << Solution().findKthLargest(nums3, 8) << endl;
    // 3

    return 0;
}
