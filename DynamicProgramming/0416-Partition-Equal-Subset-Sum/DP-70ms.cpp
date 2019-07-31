/// Source : https://leetcode.com/problems/partition-equal-subset-sum/
/// Author : Fei
/// Time   : Jul-24-2019

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

/// Dynamic Programming
/// Time Complexity: O(len(nums) * O(sum(nums)))
/// Space Complexity: O(len(nums) * O(sum(nums)))
class Solution {
public:
    bool canPartition(vector<int>& nums) {

        if( nums.size() < 2)
            return false;
        int capacity = 0;
        for( int n : nums)
            capacity += n;
        if( capacity & 1)
            return false;

        capacity = capacity >> 1;
        vector<bool> memo( 1+capacity, false);
        memo[0] = true;
        sort( nums.rbegin(), nums.rend());

        for( int i=0; i<nums.size(); ++i) {
            for( int j=capacity; j>=nums[i]; --j) {
                memo[j] = ( memo[j] || memo[ j - nums[i]] );
            }
            if( memo[capacity])
                return true;
        }

        return false;
    }
};

void printBool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    int nums1[] = {1, 5, 11, 5};
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int));
    printBool(Solution().canPartition(vec1));

    int nums2[] = {1, 2, 3, 5};
    vector<int> vec2(nums2, nums2 + sizeof(nums2)/sizeof(int));
    printBool(Solution().canPartition(vec2));

    return 0;
}
