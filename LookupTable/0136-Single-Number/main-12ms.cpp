/// Source : https://leetcode.com/problems/single-number/
/// Author : Fei
/// Time   : May-16-2019

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

/// Manipulate bit
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int res = 0;
        for( int i=0; i<nums.size(); ++i)
            res ^= nums[i];

        return res;
    }
};


int main() {

    vector<int> nums = {0, 0, 1, 1, 2};
    cout << Solution().singleNumber(nums) << endl;

    return 0;
}
