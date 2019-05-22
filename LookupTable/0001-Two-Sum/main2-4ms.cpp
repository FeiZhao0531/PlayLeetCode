/// Source : https://leetcode.com/problems/two-sum/description/
/// Author : Fei
/// Time   : May-20-2019

#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>
#include <algorithm>

using namespace std;

/// Sort and two-pointers
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> numsCopy( nums);
        sort( numsCopy.begin(), numsCopy.end());
        int l = 0, r = numsCopy.size()-1; // [l,r]
        while( l < r) {
            int sumTwoPointers = numsCopy[l] + numsCopy[r];
            if( sumTwoPointers == target)
                break;
            else if( sumTwoPointers > target)
                r --;
            else
                l ++;
        }
        if( l >= r)
            throw invalid_argument("No Solution!");

        vector<int> res;
        for( int i=0; i<nums.size(); ++i)
            if( nums[i] == numsCopy[l] || nums[i] == numsCopy[r]) {
                res.push_back( i);
                if( res.size() == 2)
                    break;
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

    vector<int> nums = {2,11,7,5};
    int target = 9;
    printVec(Solution().twoSum(nums, target));

    return 0;
}
