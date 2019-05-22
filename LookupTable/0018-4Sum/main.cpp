/// Source : https://leetcode.com/problems/4sum/
/// Author : Fei
/// Time   : May-20-2019

#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>
#include <algorithm>

using namespace std;

/// This code is learned from liuyubobobo, what a great solution!
/// Two pointers
/// Sort the array first.
/// For every different number a and b, try to find a pair (c, d), which a + b + c + d == 0
/// Using this way, we don't need to see whether the triplet is a repeated one
///
/// Time Complexity: O(nlogn) + O(n^3)
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort( nums.begin(), nums.end());
        vector< vector<int> > res;
        int len = nums.size();
        if( len < 4 || nums[len-1] + nums[len-2] + nums[len-3] + nums[len-4] < target)
            return res;

        for( int i=0; i<len-3; i=nextNumIndex( nums, i)) {

            for( int j=i+1; j<len-2; j=nextNumIndex( nums, j)) {
                int l = j + 1, r = len - 1; // [l,r]
                int complement = target - nums[i] - nums[j];
                while( l < r) {
                    int sumTwoPointers = nums[l] + nums[r];
                    if( sumTwoPointers == complement) {
                        res.push_back( { nums[i], nums[j], nums[l], nums[r]});
                        l = nextNumIndex( nums, l);
                        r = preNumIndex( nums, r);
                    }
                    else if( sumTwoPointers > complement)
                        r = preNumIndex( nums, r);
                    else
                        l = nextNumIndex( nums, l);
                }
            }
        }

        return res;
    }

private:
    int preNumIndex( const vector<int>& nums, int curIndex) {

        for( int i=curIndex-1; i>=0; i --)
            if( nums[i] != nums[curIndex])
                return i;

        return -1;
    }

    int nextNumIndex( const vector<int>& nums, int curIndex) {

        for( int i=curIndex+1; i<nums.size(); ++i)
            if( nums[i] != nums[curIndex])
                return i;

        return nums.size();
    }
};

void print_vec(const vector<vector<int>>& vec){
    for(const vector<int>& v: vec){
        for(int e: v)
            cout << e << " ";
        cout << endl;
    }
}

int main() {

    vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    int target1 = 0;
    print_vec(Solution().fourSum(nums1, target1));

    return 0;
}
