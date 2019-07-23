/// Source : https://leetcode.com/problems/house-robber/description/
/// Author : Fei
/// Time   : Jul-21-2019

#include <iostream>
#include <vector>

using namespace std;

/// Memory Search
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        memo = vector<int>( n, -1);

        return memorySearch( nums, 0);
    }
private:
    vector<int> memo;

    int memorySearch( vector<int>& nums, int p) {

        if( p >= nums.size())
            return 0;
        if( memo[p] != -1)
            return memo[p];

        return memo[p] = max( nums[p] + memorySearch( nums, p+2),
                      memorySearch( nums, p+1));
    }
};

int main() {

    int nums[] = {2,7,9,3,1};
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int));

    cout << Solution().rob(vec) << endl;

    return 0;
}
