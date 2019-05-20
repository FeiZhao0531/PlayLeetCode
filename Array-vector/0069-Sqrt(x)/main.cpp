/// Source : https://leetcode.com/problems/sqrtx/description/
/// Author : Fei
/// Time   : May-20-2019

#include <iostream>
#include <cassert>
using namespace std;


/// Binary Search
/// Using double first
///
/// Time Complexity: O(log(MAX_INT) * precision)
/// Space Complexity: O(1)
class Solution {
public:
    int mySqrt(int x) {

        assert( x >= 0);
        if( x == 0 || x == 1)
            return x;
        int l = 1, r = x / 2;
        while( l <= r) {
            int mid = l + ( r - l) / 2;
            if( mid > x / mid)
                r = mid - 1;
            else { // mid <= x / mid
                if( mid + 1 > x / (mid + 1))
                    return mid;
                l = mid + 1;
            }
        }

        return -1;
    }
};


int main() {

    cout << Solution().mySqrt(4) << endl;
    cout << Solution().mySqrt(8) << endl;

    return 0;
}
