/// Source : https://leetcode.com/problems/n-queens-ii/
/// Author : Fei
/// Time   : Jul-02-2019

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

/// Basic Recursive
/// Time Complexity: O(n!)
/// Space Complexity: O(n)
class Solution {
public:
    int totalNQueens(int n) {

        if( n == 1)
            return 1;
        if( n < 4)
            return 0;
        this->n = n;
        col = vector<bool>( n ,false);
        dia1 = vector<bool>( n, false);
        dia2 = vector<bool>( n, false);
        int num = 0;
        helper( 0, num);

        return num;
    }
private:
    int n;
    vector<bool> col, dia1, dia2;

    void helper( int rowIndex, int& num) {

        if( rowIndex == n) {
            num ++;
            return;
        }

        for( int i=0; i<n; ++i) {
            if( !col[i] && !dia1[ rowIndex + i] && !dia2[ rowIndex - i + n - 1]) {
                col[i] = true;
                dia1[ rowIndex + i] = true;
                dia2[ rowIndex - i + n - 1] = true;
                helper( rowIndex + 1, num);
                col[i] = false;
                dia1[ rowIndex + i] = false;
                dia2[ rowIndex - i + n - 1] = false;
            }
        }
    }
};

int main() {

    const int n = 10;
    for( int i=0; i <= n; ++i)
        cout << i << "  " << Solution().totalNQueens(i) << endl;
    return 0;
}
