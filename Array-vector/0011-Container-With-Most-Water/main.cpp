/// Source : https://leetcode.com/problems/container-with-most-water/
/// Author : Fei
/// Time   : May-9-2019

#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>
using namespace std;

/// Two Pointers
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {

        assert( height.size() >= 2);
        int l = 0, r = height.size() - 1;
        int maxA = 0;
        while( l < r) {
            maxA = max( maxA, min( height[l], height[r]) * ( r - l));
            if( height[l] > height[r])
                r --;
            else
                l ++;
        }

        return maxA;
    }
};


int main() {

    vector<int> nums1 = {1,8,6,2,5,4,8,3,7};
    cout << Solution().maxArea(nums1) << endl;

    return 0;
}
