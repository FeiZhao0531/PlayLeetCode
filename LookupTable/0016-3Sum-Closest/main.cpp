/// Source : https://leetcode.com/problems/3sum-closest/
/// Author : Fei
/// Time   : May-20-2019

#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>
#include <algorithm>

using namespace std;


/// Sorting + Two Pointers
/// Time Complexity: O(nlogn) + O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort( nums.begin(), nums.end());
        int len = nums.size();
        int res = 0, minGap = INT_MAX;
        for( int i=0; i<=len-3; i=nextNumIndex( nums, i)) {
            int l = i + 1, r = len - 1; // [ l, r]
            while( l < r) {
                int sum3 = nums[i] + nums[l] + nums[r];
                int gap = abs( sum3 - target);
                if( gap < minGap) {
                    minGap = gap;
                    res = sum3;
                }

                if( sum3 > target)
                    r = preNumIndex( nums, r);
                else if( sum3 < target)
                    l = nextNumIndex( nums, l);
                else
                    return target;
            }
        }

        return res;
    }
private:
    int nextNumIndex( const vector<int>& nums, int curIndex) {

        assert( curIndex >= 0 && curIndex < nums.size());
        for( int i=curIndex; i<nums.size(); ++i)
            if( nums[i] != nums[curIndex])
                return i;

        return nums.size();
    }

    int preNumIndex( const vector<int>& nums, int curIndex) {

        assert( curIndex >= 0 && curIndex < nums.size());
        for( int i=curIndex; i>=0; i--)
            if( nums[i] != nums[curIndex])
                return i;

        return -1;
    }
};


int main() {

    vector<int> nums1 = {-1, 2, 1, -4};
    int target = 1;
    cout << Solution().threeSumClosest(nums1, target ) << endl;

    return 0;
}
