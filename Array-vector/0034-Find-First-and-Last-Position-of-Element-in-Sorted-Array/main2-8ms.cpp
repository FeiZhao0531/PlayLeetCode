/// Source : https://leetcode.com/problems/search-for-a-range/description/
/// Author : Fei
/// Time   : May-20-2019

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Real Binary Search compared to the solution1
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> res( 2, -1);
        if( nums.size() == 0 || *nums.begin() > target || *nums.rbegin() < target)
            return res;
        int lowerRange = lowerBound( nums, target);
        int higherRange = lowerBound( nums, target + 1) - 1;

        if( lowerRange < nums.size() && nums[lowerRange] == target)
            res[0] = lowerRange, res[1] = higherRange;
        return res;
    }
private:
    int lowerBound( vector<int>& nums, int target) {

        int l = 0, r = nums.size() - 1; // nums [l,r]
        while( l <= r) {
            int mid = l + ( r - l) / 2;
            if( nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return l;
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
