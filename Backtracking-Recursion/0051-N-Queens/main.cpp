/// Source : https://leetcode.com/problems/n-queens/description/
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
private:
    int n;
    vector<bool> col, dia1, dia2; // dia1 : / ; dia2 : \ ,
    vector<vector<string>> res;

    void helper( int rowIndex, vector<int>& colIndex) {

        if( rowIndex == n) {
            res.push_back( toString( colIndex));
            return;
        }
        for( int i=0; i<n; ++i) {
            if( !col[i] && !dia1[ rowIndex + i] && !dia2[ rowIndex - i + n - 1]) {
                colIndex.push_back( i);
                col[i] = true;
                dia1[ rowIndex + i] = true;
                dia2[ rowIndex - i + n - 1] = true;
                helper( rowIndex + 1, colIndex);
                colIndex.pop_back();
                col[i] = false;
                dia1[ rowIndex + i] = false;
                dia2[ rowIndex - i + n - 1] = false;
            }
        }
    }

    vector<string> toString( vector<int>& tmp) {

        assert( tmp.size() == n);
        vector<string> ans( n, string( n, '.'));
        for( int i=0; i<n; ++i)
            ans[i][tmp[i]] = 'Q';

        return ans;
    }

public:
    vector<vector<string>> solveNQueens(int n) {

        res.clear();
        if( n == 1) {
            res.push_back( vector<string>{"Q"});
            return res;
        }
        if( n < 4)
            return res;

        this->n = n;
        col = vector<bool>( n, false);
        dia1 = vector<bool>( 2*n-1, false);
        dia2 = vector<bool>( 2*n-1, false);
        vector<int> colIndex;
        helper( 0, colIndex);

        return res;
    }
};

template <typename T>
void print2DVec( const vector< vector<T> >& board){

    auto iter = board.begin();
    for( ; iter != board.end(); ++iter) {
        for( T n : *iter)
            cout << n << " " << endl;
        cout << endl;
    }
    cout << " Print Complete. " << endl << endl;
}

int main() {

    const int n = 8;
    vector<vector<string>> res = Solution().solveNQueens(n);
    print2DVec( res);

    return 0;
}
