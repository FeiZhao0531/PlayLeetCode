/// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
/// Author : Fei
/// Time   : Jul-23-2019

#include <iostream>
#include <vector>

using namespace std;

/// Dynamic Programming
/// Many thanks to this article
///      https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/yi-ge-tong-yong-fang-fa-tuan-mie-6-dao-gu-piao-wen/
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        if( n == 0) return 0;
        int dp_0 = 0, dp_1 = - prices[0];
        for( int i=1; i<n; ++i) {
            dp_0 = max( dp_0, dp_1 + prices[i]);
            dp_1 = max( dp_1, dp_0 - prices[i]);
        }

        return dp_0;
    }
};

int main() {

    vector<int> nums = {7,1,5,3,6,4};
    cout << Solution().maxProfit(nums) << endl;

    return 0;
}
