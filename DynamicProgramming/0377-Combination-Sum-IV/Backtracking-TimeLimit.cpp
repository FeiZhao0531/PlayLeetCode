/// Source : https://leetcode.com/problems/combination-sum-iv/
/// Author : Fei
/// Time   : Jul-25-2019

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Naive Backtracking
/// Need to sort the vector at first
/// Time Complexity: O(n ^ target)
/// Space Complexity: O(1)
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {

        sort( nums.begin(), nums.end());
        if( nums.size() == 0 || nums[0] > target)
            return res;
        this->target = target;

        dfs( nums, 0, 0);
        cout << counter << endl;
        return res;
    }
private:
    int target;
    int res = 0;
    int counter = 0;

    void dfs( const vector<int>& nums, int p, int sum) {

        counter ++;

        if( sum == target) {
            res ++;
            return;
        }

        for( int i=0; i<nums.size(); ++i) {
            if( sum + nums[i] > target) return;
            dfs( nums, i, sum + nums[i]);
        }
    }
};


int main() {

    vector<int> nums1 = { 2, 1, 3};
    int target1 = 32;
    cout << Solution().combinationSum4(nums1, target1) << endl;

    return 0;
}
