/// Source : https://leetcode.com/problems/two-sum/description/
/// Author : Fei
/// Time   : Jul-01-2019

#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <cassert>

using namespace std;


/// DFS
/// Time Complexity: O(m+n)
/// Space Complexity: O(m)
///
/// Only need to consider the 4 edges of board
/// keep the 'O' area on the edges, and change all the others to 'X'
class Solution {
public:
    void solve(vector<vector<char>>& board) {

        if( board.size() <= 2 || board[0].size() <= 2) return;
        xUp = board.size();
        yUp = board[0].size();

        for( int y=0; y < yUp; ++y) {
            if( board[0][y] == 'O') planeDFS( board, 0, y);
            if( board[xUp-1][y] == 'O') planeDFS( board, xUp-1, y);
        }
        for( int x=1; x < xUp - 1; ++x) {
            if( board[x][0] == 'O') planeDFS( board, x, 0);
            if( board[x][yUp-1] == 'O') planeDFS( board, x, yUp-1);
        }

        for( int x=0; x < xUp; ++x)
            for( int y=0; y < yUp; ++y) {
                if( board[x][y] != '#')
                    board[x][y] = 'X';
                else
                    board[x][y] = 'O';
            }

        return;
    }
private:
    int nextStep[4][2] = { { 0, 1}, { 1, 0}, { 0, -1}, { -1, 0}};
    int xUp, yUp;
    void planeDFS( vector< vector<char> >& board, int x, int y) {

        if( board[x][y] == 'X') return;
        board[x][y] = '#';
        for( int i=0; i<4; ++i) {
            int newX = x + nextStep[i][0];
            int newY = y + nextStep[i][1];
            if( inArea( newX, newY) && board[newX][newY] == 'O')
                planeDFS( board, newX, newY);
        }
    }

    inline bool inArea( int x, int y) {

        return ( x >= 0 && x < xUp) && ( y >= 0 && y < yUp);
    }
};


int main(){

    int n = 4, m = 4;
    string board_array[] = {
            "XXXX",
            "XOOX",
            "XXOX",
            "XOXX"};
    vector<vector<char>> board = vector<vector<char>>(n, vector<char>(m, ' '));
    for(int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < m ; j ++)
            board[i][j] = board_array[i][j];

    Solution().solve(board);

    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++)
            cout << board[i][j];
        cout << endl;
    }

    return 0;
}
