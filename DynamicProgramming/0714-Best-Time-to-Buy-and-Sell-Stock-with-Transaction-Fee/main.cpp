/// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
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
    int maxProfit(vector<int>& prices, int fee) {

        int n = prices.size();
        if( n == 0) return 0;

        int noStock = 0, inStock = - prices[0] - fee;
        for( int i=1; i<n; ++i) {
            noStock = max( noStock, inStock + prices[i]);
            inStock = max( inStock, noStock - prices[i] - fee);
        }

        return noStock;
    }
};

int main() {

    vector<int> nums = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << Solution().maxProfit( nums, fee) << endl;

    return 0;
}
