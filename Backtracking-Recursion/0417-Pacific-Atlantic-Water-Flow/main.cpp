/// Source : https://leetcode.com/problems/pacific-atlantic-water-flow/
/// Author : Fei
/// Time   : Jul-01-2019

#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <cassert>

using namespace std;


/// DFS
/// Time Complexity: O(m*n)
/// Space Complexity: O(m*n)
///
/// Only need to consider the 4 edges of board
/// Flood Fill from edge to the centre
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {

        vector< vector<int> > res;
        if( matrix.size() == 0 || matrix[0].size() == 0)
            return res;

        xUp = matrix.size();
        yUp = matrix[0].size();
        vector< vector<bool> > toPacific( xUp, vector<bool>( yUp, false));
        vector< vector<bool> > toAtlantic( xUp, vector<bool>( yUp, false));

        for( int x=0; x < xUp; ++x) {
            planeDFS( matrix, x, 0, toPacific);
            planeDFS( matrix, x, yUp-1, toAtlantic);
        }
        for( int y=0; y < yUp; ++y) {
            planeDFS( matrix, 0, y, toPacific);
            planeDFS( matrix, xUp-1, y, toAtlantic);
        }

        for( int x=0; x < xUp; ++x)
            for( int y=0; y < yUp; ++y)
                if( toPacific[x][y] && toAtlantic[x][y])
                    res.push_back( { x, y});

        return res;
    }
private:
    int nextStep[4][2] = { { 0, 1}, { 1, 0}, { 0, -1}, { -1, 0}};
    int xUp, yUp;

    void planeDFS( const vector< vector<int> >& matrix, int x, int y, vector< vector<bool> >& record) {

        record[x][y] = true;
        for( int i=0; i<4; ++i) {
            int newX = x + nextStep[i][0];
            int newY = y + nextStep[i][1];
            if( inArea( newX, newY) && matrix[newX][newY] >= matrix[x][y] && !record[newX][newY])
                planeDFS( matrix, newX, newY, record);
        }
    }

    bool inArea( int x, int y) {

        return ( x >= 0 && x < xUp) && ( y >= 0 && y < yUp);
    }
};

void print2DVec( const vector< vector<int> >& matrix) {

    auto iter = matrix.begin();
    for( ; iter != matrix.end(); ++iter) {
        for( int n : *iter)
            cout << n << ", ";
        cout << endl;
    }
    cout << " Print Complete." << endl << endl;
}
int main(){

    const int n = 5, m = 5;
    const int board_array[n][m] = {
        { 1, 2, 2, 3, 5},
        { 3, 2, 3, 4, 4},
        { 2, 4, 5, 3, 1},
        { 6, 7, 1, 4, 5},
        { 5, 1, 1, 2, 4},
    };
    vector<vector<int>> matrix = vector<vector<int>>(n, vector<int>(m, 0));
    for(int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < m ; j ++)
            matrix[i][j] = board_array[i][j];

    print2DVec( Solution().pacificAtlantic( matrix));
    return 0;
}
