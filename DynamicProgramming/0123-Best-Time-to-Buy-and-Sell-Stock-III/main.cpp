/// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
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
        int noStock_0 = 0, inStock_0 = - prices[0];
        int noStock_1 = 0, inStock_1 = INT_MIN;

        for( int i=1; i<n; ++i) {
            noStock_0 = max( noStock_0, inStock_0 + prices[i]);
            inStock_0 = max( inStock_0, - prices[i]);
            noStock_1 = max( noStock_1, inStock_1 + prices[i]);
            inStock_1 = max( inStock_1, noStock_0 - prices[i]);
        }

        return max( noStock_0, noStock_1);
    }
};

int main() {

    vector<int> nums = {7,1,5,3,6,4};
    cout << Solution().maxProfit(nums) << endl;

    return 0;
}
