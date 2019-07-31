/// Source : https://leetcode.com/problems/target-sum/description/
/// Author : Fei
/// Time   : Jul-28-2019

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Memory Search
/// Using TreeMap
///
/// Time Complexity: O(n * maxNum * log(n * maxNum))
/// Space Complexity: O(n * maxNum)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {

        int sum = 0;
        for( int n : nums)
            sum += n;
        if( abs(sum) < abs(S))
            return 0;

        return memorySearch( nums, nums.size()-1, S);
    }

private:
    map<pair<int,int>,int> memo; // pair: p, S

    int memorySearch( const vector<int>& nums, int p, int S) {

        if( p == -1)
            return S == 0;
        pair<int,int> pS = make_pair( p, S);
        if( memo.count( pS))
            return memo[pS];

        memo[pS] = memorySearch( nums, p - 1, S + nums[p])
                    + memorySearch( nums, p - 1, S - nums[p]);

        return memo[pS];
    }
};

int main() {

    vector<int> nums = {1, 1, 1, 1, 1};
    cout << Solution().findTargetSumWays(nums, 3) << endl;

    return 0;
}
