///  source: https://leetcode.com/problems/kth-largest-element-in-an-array/
///  author: Fei Zhao
///  creating time: May-8-2019

#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class Solution {

//  Time complexity: O( nlogk)
//  Space complexity: O( k)
public:
    int findKthLargest(vector<int>& nums, int k) {

        assert( k >= 1 && k <= nums.size());
        priority_queue< int, vector<int>, greater<int>> pq;
        for( int e : nums) {
            if( pq.size() != k)
                pq.push(e);
            else {
                if( e > pq.top()) {
                    pq.pop();
                    pq.push(e);
                }
            }
        }
        return pq.top();
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
