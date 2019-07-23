/// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
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
    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();
        if( n == 0 || k == 0) return 0;
        if( k > n / 2 + 1)
            return maxProfit( prices);

        vector<int> noStock( k, 0);
        vector<int> inStock( k, - prices[0]);
        for( int i=1; i<n; ++i) {
            for( int j=0; j < min( i, k); ++j) {
                noStock[j] = max( noStock[j], inStock[j] + prices[i]);
                inStock[j] = max( inStock[j],
                                    ( j == 0 ? 0 : noStock[j-1]) - prices[i]);
            }
        }

        int res = INT_MIN;
        for( int i=0; i<k; ++i)
            res = max( res, noStock[i]);

        return res;
    }

private:
    int maxProfit( vector<int>& prices) {

        int n = prices.size();
        if( n == 0) return 0;
        int noStock = 0, inStock = - prices[0];
        for( int i=1; i<n; ++i) {
            noStock = max( noStock, inStock + prices[i]);
            inStock = max( inStock, noStock - prices[i]);
        }

        return noStock;
    }
};

int main() {

    vector<int> nums = {7,1,5,3,6,4};
    cout << Solution().maxProfit( 2, nums) << endl;

    return 0;
}
