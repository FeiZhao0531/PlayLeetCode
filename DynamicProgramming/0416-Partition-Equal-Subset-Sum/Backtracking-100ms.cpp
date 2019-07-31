/// Source : https://leetcode.com/problems/partition-equal-subset-sum/
/// Author : Fei
/// Time   : Jul-24-2019

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

/// Backtracking
/// Time Complexity: O(len(nums)!)
/// Space Complexity: O(1)
class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int capacity = 0;
        for( int n : nums)
            capacity += n;
        if( capacity % 2 == 1)
            return false;

        sort( nums.begin(), nums.end());

        return dfs( nums, nums.size()-1, capacity / 2);
    }

private:
    bool dfs( const vector<int>& nums, int p, int capacity) {

        for( int i=p; i>=0; i=prevIndex( nums, i)) {

            if( nums[i] > capacity) continue;
            if( nums[i] == capacity)
                return true;
            if( dfs( nums, i - 1, capacity - nums[i]))
                return true;
        }

        return false;
    }

    int prevIndex( const vector<int>& nums, int p) {

        assert( p <= nums.size()-1 && p >= 0);
        for( int i=p; i>=0; --i)
            if( nums[i] != nums[p])
                return i;

        return -1;
    }
};

void printBool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    int nums1[] = {1, 5, 11, 5};
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int));
    printBool(Solution().canPartition(vec1));

    int nums2[] = { 71,70,66,54,32,63,38,98,4,22,61,40,6,8,6,21,71,36,
                    30,34,44,60,89,53,60,56,73,14,63,37,15,58,51,88,88,
                    32,80,32,10,89,67,29,68,65,34,15,88,8,57,78,37,63,
                    73,65,47,39,32,74,31,44,43,4,10,8,96,22,58,87,29,99,
                    79,13,96,21,62,71,34,55,72,3,96,7,36,64,30,6,14,87,
                    12,90,40,13,29,21,94,33,99,86,4,100};
    vector<int> vec2(nums2, nums2 + sizeof(nums2)/sizeof(int));
    printBool(Solution().canPartition(vec2));

    int nums3[] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,100 };
    vector<int> vec3(nums3, nums3 + sizeof(nums3)/sizeof(int));
    printBool(Solution().canPartition(vec3));

    return 0;
}
