/// Source : https://leetcode.com/problems/number-of-islands/description/
/// Author : Fei
/// Time   : Jul-01-2019

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Floodfill - DFS
/// Recursion implementation
///
/// Time Complexity: O(n*m)
/// Space Complexity: O(n*m)
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        if( grid.size() == 0 || grid[0].size() == 0)
            return 0;
        xUp = grid.size();
        yUp = grid[0].size();
        gridCopy = vector< vector<char> >( grid); // avoid change on the input grid

        int num = 0;
        for( int x=0; x < xUp; ++x)
            for( int y=0; y < yUp; ++y)
                if( gridCopy[x][y] == '1') {
                    planeDFS( x, y);
                    num ++;
                }

        return num;
    }
private:
    int xUp, yUp;
    vector< vector<char> > gridCopy;
    int nextStep[4][2] = { { 0, 1}, { 1, 0}, { 0, -1}, { -1, 0}};

    void planeDFS( int x, int y) {

        gridCopy[x][y] = '0';
        for( int i=0; i<4; ++i) {
            int newX = x + nextStep[i][0];
            int newY = y + nextStep[i][1];
            if( inArea( newX, newY) && gridCopy[newX][newY] == '1')
                planeDFS( newX, newY);
        }
    }

    bool inArea( int x, int y){

        return ( x >= 0 && x < xUp) && ( y >= 0 && y < yUp);
    }
};

int main() {

    char g1[4][5] = {
            {'1','1','1','1','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','0'},
            {'0','0','0','0','0'}
    };
    vector<vector<char>> grid1;
    for(int i = 0 ; i < 4 ; i ++)
        grid1.push_back( vector<char>(g1[i], g1[i] + sizeof( g1[i])/sizeof(char)));

    cout << Solution().numIslands(grid1) << endl;
    // 1

    // ---

    char g2[4][5] = {
            {'1','1','0','0','0'},
            {'1','1','0','0','0'},
            {'0','0','1','0','0'},
            {'0','0','0','1','1'}
    };
    vector<vector<char>> grid2;
    for(int i = 0 ; i < 4 ; i ++)
        grid2.push_back(vector<char>(g2[i], g2[i] + sizeof( g2[i])/sizeof(char)));

    cout << Solution().numIslands(grid2) << endl;
    // 2

    return 0;
}
