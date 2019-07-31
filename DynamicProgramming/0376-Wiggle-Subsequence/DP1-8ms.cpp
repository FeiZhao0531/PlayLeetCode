/// Source : https://leetcode.com/problems/longest-increasing-subsequence/
/// Author : Fei
/// Time   : Jul-31-2019

#include <iostream>
#include <vector>
using namespace std;

/// Dynamic Programming #1
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {

        int n = nums.size();
        if( n <= 1)
            return n;

        int maxWLen = 1;
        vector<int> up( n, 1), down( n, 1);
        for( int i = 1; i < n; ++ i) {
            for( int j = 0; j < i; ++ j) {
                if( nums[i] > nums[j])
                    up[i] = max( up[i], down[j] + 1);
                if( nums[i] < nums[j])
                    down[i] = max( down[i], up[j] + 1);
            }
            maxWLen = max( maxWLen, max( up[i], down[i]));
        }

        return maxWLen;
    }
};

int main() {

    int nums1[] = { 1,7,4,9,2,5};
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int));
    cout << Solution().wiggleMaxLength(vec1) << endl;

    return 0;
}
