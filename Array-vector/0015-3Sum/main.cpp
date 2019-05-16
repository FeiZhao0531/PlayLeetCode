/// Source : https://leetcode.com/problems/3sum/
/// Author : Fei
/// Time   : May-15-2019

#include <iostream>
#include <vector>
#include <algorithm>
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
        for(int i=0; i< nums.size()-2; ++i) {
            if(nums[i] + nums[i+1] + nums[i+2] > 0)
                break;
            if(nums[i] + nums[len-2] + nums[len-1] < 0)
                continue;

            int target = - nums[i];
            int l = i + 1;
            int r = nums.size()-1;
            while( l < r) {
                if( nums[l] + nums[r] == target) {
                    vector<int> triplets(3,0);
                    triplets[0] = nums[i];
                    triplets[1] = nums[l];
                    triplets[2] = nums[r];
                    if( res.empty() || res.back() != triplets )
                        res.push_back(triplets);

                    while(l < r && nums[l]==triplets[1])
                        l++;
                    while(l < r && nums[r]==triplets[2])
                        r--;
                }
                else if(nums[l] + nums[r] < target)
                    l++;
                else
                    r--;
            }
            while(i+2 < nums.size() && nums[i] == nums[i+1])
                i++;
        }
        return res;
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
