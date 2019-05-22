/// Source : https://leetcode.com/problems/3sum/
/// Author : Fei
/// Time   : May-20-2019

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

/// Two pointers
///
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {

        int len = nums.size();
        if( nums.size() < 3)
            return {};
        sort(nums.begin(),nums.end());
        if( nums[0] + nums[1] + nums[2] > 0 || nums[len-1] + nums[len-2] + nums[len-3] < 0)
            return {};

        vector< vector<int> > res;
        for( int i=0; i<=len-3; i=nextNumIndex( nums, i)) {
            int l = i + 1, r = len - 1;
            while( l < r) {
                if( nums[l] + nums[r] > - nums[i])
                    r = preNumIndex( nums, r);
                else if( nums[l] + nums[r] < - nums[i])
                    l = nextNumIndex( nums, l);
                else {
                    res.push_back( {nums[i], nums[l], nums[r]});
                    l = nextNumIndex( nums, l);
                    r = preNumIndex( nums, r);
                }
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
        for( int i=curIndex; i>=0; i --)
            if( nums[i] != nums[curIndex])
                return i;

        return -1;
    }
};

int main() {

    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = Solution().threeSum(nums1);
    for( int i = 0 ; i < res.size() ; i ++ ){
        for( int j = 0 ; j < res[i].size() ; j ++ )
            cout<<res[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
