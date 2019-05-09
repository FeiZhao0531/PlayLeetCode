///  source: https://leetcode.com/problems/kth-largest-element-in-an-array/
///  author: Fei Zhao
///  creating time: May-8-2019

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
//  Time complexity: O( n)
//  Space complexity: O( logn)
public:
    int findKthLargest(vector<int>& nums, int k) {

        assert( k <= nums.size() && k >= 1);
        k = nums.size() - k;
        int l = 0, r = nums.size() - 1, index = 0;
        while( l <= r) {
            index = partition( nums, l, r);
            if( index == k)
                break;
            else if( index < k)
                l = index + 1;
            else
                r = index - 1;
        }
        return nums[index];
    }

private:

    // in the range of [ l, r] to find the target
    int partition( vector<int>& nums, int l, int r) {

        int pivot = nums[l], i = l, j = r;
        // nums[l,i) <= pivot, nums(j,r] >= pivot
        while( i < j) {
            while( i < j && nums[j] >= pivot)
                j --;
            nums[i] = nums[j];
            while( i < j && nums[i] <= pivot)
                i ++;
            nums[j] = nums[i];
        }
        nums[i] = pivot;

        return i;
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
