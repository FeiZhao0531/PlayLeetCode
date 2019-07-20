/// Source : https://leetcode.com/problems/integer-break/description/
/// Author : Fei
/// Time   : Jul-18-2019

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Memory Search
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int integerBreak(int n) {

        assert( n >= 2);
        memo = vector<int>( 1 + n, -1);

        return memorySearch( n);
    }

//    void printMemo() {
//
//        for( int i : memo)
//            cout << i << " ";
//
//        cout << endl;
//        cout << "Counters = " << counter << endl;
//    }

private:
    vector<int> memo;
    int counter = 0;

    int memorySearch( int n) {

        counter ++;
        if( n == 1) return 1;

        for( int i=1; i<n; ++i) {

            if( memo[i] == -1)  memo[i] = memorySearch( i);
            memo[n] = max3( memo[n], ( n - i)*memo[ i], i*( n - i));
        }

        return memo[n];
    }

    inline static int max3( int a, int b, int c) { return max( a, max( b, c));}
};

int main() {

    Solution s;
    s.integerBreak( 15);
    s.printMemo();

    return 0;
}
