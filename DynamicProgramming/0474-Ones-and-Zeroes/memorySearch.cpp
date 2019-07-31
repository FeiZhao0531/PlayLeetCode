/// Source : https://leetcode.com/problems/ones-and-zeroes/
/// Author : Fei
/// Time   : Jul-26-2019

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/// 2 limits for 0-1backpack problem
/// Dynamic Programming with space optimization
/// Time Complexity: O( sizeof(array)*m*n)
/// Space Complexity: O( sizeof(array)*m*n)
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        vector< vector<int> > memo( 1+m, vector<int>( 1+n, 0)); // store the states
        int nums0s, nums1s;

        for( auto &s : strs) {
            nums0s = nums1s = 0;
            for( auto c : s) {
                assert( c == '0' || c == '1');
                if( c == '0')
                    nums0s++;
                else
                    nums1s++;
            }

            for( int i=m; i>=nums0s; --i) {
                for( int j=n; j>=nums1s; --j)
                    memo[i][j] = max( memo[i][j], memo[i-nums0s][j-nums1s] + 1);
            }
        }
        return memo[m][n];
    }

public:
    int findMaxForm( vector<string>& strs, int m, int n) {

        dp = vector< vector< vector<int> > >( strs.size(), vector< vector<int> >( 1 + m, vector<int>( 1 + n, 0)));
    }

private:
    vector< vector< vector<int> > > dp;

    int memorySearch( const vector<string>& strs, int p, int rest_m, int res_n) {

        if( dp[p][rest_m][rest_])
    }
};


int main() {

    vector<string> vec1 = {"10", "001", "111001", "1", "0"};
    int m1 = 5;
    int n1 = 3;
    cout << Solution().findMaxForm(vec1, m1, n1) << endl;

    vector<string> vec2 = {"10", "0", "1"};
    int m2 = 1;
    int n2 = 1;
    cout << Solution().findMaxForm(vec2, m2, n2) << endl;

    return 0;
}
