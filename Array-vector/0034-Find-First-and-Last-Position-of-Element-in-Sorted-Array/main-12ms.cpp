/// Source : https://leetcode.com/problems/search-for-a-range/description/
/// Author : Fei
/// Time   : May-18-2019

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Binary Search
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> res = { -1, -1};
        int l = 0, r = nums.size()-1; // in nums[l,r] to find target
        int targetIndex = -1;
        while( l <= r) {
            int mid = l + ( r - l) / 2;
            if( nums[mid] > target)
                r = mid - 1;
            else if( nums[mid] < target)
                l = mid + 1;
            else {
                targetIndex = mid;
                break;
            }
        }

        if( targetIndex == -1)
            return res;
        else {
            l = targetIndex - 1, r = targetIndex + 1;
            while( l >= 0 && nums[l] == target)
                l --;
            while( r < nums.size() && nums[r] == target)
                r ++;

            res[0] = l + 1, res[1] = r - 1;
        }

        return res;
    }
};


void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    int nums1[6] = {5, 7, 7, 8, 8, 10};
    int target1 = 8;
    vector<int> vec1(nums1, nums1 + sizeof(nums1) / sizeof(int));

    printVec(Solution().searchRange(vec1, target1));
    // 3, 4

    // ---

    int nums2[1] = {1};
    int target2 = 0;
    vector<int> vec2(nums2, nums2 + sizeof(nums2) / sizeof(int));

    printVec(Solution().searchRange(vec2, target2));
    // -1, -1

    // ---

    int nums3[1] = {1};
    int target3 = 1;
    vector<int> vec3(nums3, nums3 + sizeof(nums3) / sizeof(int));

    printVec(Solution().searchRange(vec3, target3));
    // 0, 0

    // ---
    vector<int> vec4;
    printVec(Solution().searchRange(vec4, 0));
    // -1, -1

    return 0;
}
