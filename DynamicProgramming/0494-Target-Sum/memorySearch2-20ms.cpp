/// Source : https://leetcode.com/problems/target-sum/description/
/// Author : Fei
/// Time   : Jul-28-2019

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Memory Search
/// Using 2D-Array
///
/// Time Complexity: O(n * maxNum)
/// Space Complexity: O(n * maxNum)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {

        int sum = 0;
        for( int n : nums)
            sum += n;
        if( abs(sum) < abs(S))
            return 0;

        memo = vector< vector<int> >( nums.size(), vector<int>( 2001, 2001));

        return memorySearch( nums, nums.size()-1, S);
    }

private:
    vector< vector<int> > memo;

    int memorySearch( const vector<int>& nums, int p, int S) {

        if( p == -1)
            return S == 0;
        if( S < -1000 || S > 1000)
            return 0;
        if( memo[p][S + 1000] != 2001)
            return memo[p][S + 1000];

        memo[p][S + 1000] = memorySearch( nums, p - 1, S + nums[p])
                    + memorySearch( nums, p - 1, S - nums[p]);

        return memo[p][S + 1000];
    }
};

int main() {

    vector<int> nums = { 0,0,0,0,0,0,0,1000};
    cout << Solution().findTargetSumWays(nums, -1000) << endl;

    return 0;
}
