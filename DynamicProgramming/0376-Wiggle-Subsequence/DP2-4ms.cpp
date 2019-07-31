/// Source : https://leetcode.com/problems/longest-increasing-subsequence/
/// Author : Fei
/// Time   : Jul-31-2019

#include <iostream>
#include <vector>
using namespace std;

/// Dynamic Programming #2 with the compression of states space
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {

        int n = nums.size();
        if( n <= 1)
            return n;
        int up = 1, down = 1;
        // Up - next one should be larger
        // Down - next one should be smaller

        for( int i=1; i<n; ++i) {
            if( nums[i] > nums[i-1])
                up = down + 1;
            if( nums[i] < nums[i-1])
                down = up + 1;
        }

        return max( up, down);
    }
};

int main() {

    int nums1[] = { 1,7,4,9,2,5};
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int));
    cout << Solution().wiggleMaxLength(vec1) << endl;

    return 0;
}
