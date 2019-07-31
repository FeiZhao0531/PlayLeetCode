/// Source : https://leetcode.com/problems/partition-equal-subset-sum/
/// Author : Fei
/// Time   : Jul-27-2019

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

/// memorySearch
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

        memo = vector< vector<int>>( nums.size(), vector<int>(1 + capacity / 2, -1));
        memo[0] = 1;

        return memorySearch( nums, nums.size()-1, capacity / 2);
    }
private:
    vector< vector<int> > memo;

    int memorySearch( const vector<int>& nums, int p, int capacity) {

        if( memo[p][capacity] != -1)
            return memo[p][capacity];
        if( capacity < 0)
            return 0;

        memo[p][capacity] = memorySearch( nums, p - 1, capacity)
                            || memorySearch( nums, p, capacity - nums[p]);

        return memo[p][capacity];
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
