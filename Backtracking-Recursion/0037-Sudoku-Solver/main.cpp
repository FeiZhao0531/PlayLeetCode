/// Source : https://leetcode.com/problems/sudoku-solver/description/
/// Author : Fei
/// Time   : Jul-02-2019

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Backtracking
/// Time Complexity: O(n^{need to fill})
/// Space Complexity: O(9*9) = O(constant)
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {

        _solveSudoku( board, 0, 0);
        return;
    }
private:

    bool _solveSudoku( vector<vector<char>>& board, int i, int j) {

        if( i == 9)
            return true;
        if( j == 9)
            return _solveSudoku( board, i+1, 0);
        for( char c = '1'; c <= '9'; c++) {
            if( board[i][j] != '.')
                return _solveSudoku( board, i, j+1);
            if( check( board, i, j, c)) {
                board[i][j] = c;
                if ( _solveSudoku( board, i, j+1))
                    return true;;
                board[i][j] = '.';
            }
        }
        return false;
    }

    bool check( vector< vector<char> >& board, int x, int y, char val) {

        for( int i=0; i<9; ++i) {
            if( board[x][i] == val)
                return false;
            if( board[i][y] == val)
                return false;
            if( board[x-x%3+i/3][y-y%3+i%3] == val)
                return false;
        }
        return true;
    }
};


int main() {

    return 0;
}
