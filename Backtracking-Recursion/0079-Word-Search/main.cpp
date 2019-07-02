/// Source : https://leetcode.com/problems/word-search/description/
/// Author : Fei
/// Time   : Jul-01-2019

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// Backtrack
// Time Complexity: O(m*n*length(word))
// Space Complexity: O(m*n)
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        if( board.size() == 0 || board[0].size() == 0)
            return false;
        if( word.size() == 0)
            return true;

        xUp = board.size();
        yUp = board[0].size();
        visited = vector< vector<bool> >( xUp, vector<bool>( yUp, false)); // false : Non-visited

        for( int y=0; y < yUp; ++y)
            for( int x=0; x < xUp; ++x)
                if(  planeDFS( board, word, 0, x, y))
                    return true;

        return false;
    }
private:
    int xUp, yUp;
    int nextStep[4][2] = { { 0, 1}, { 1, 0}, { -1, 0}, { 0, -1}};
    vector< vector<bool> > visited;

    bool planeDFS( const vector< vector<char> >& board, const string& word,
                  int strIndex, int x, int y) {

        if( strIndex == word.size()-1)
            return word[strIndex] == board[x][y];
        if( word[strIndex] != board[x][y])
            return false;

        visited[x][y] = true;
        for( int i=0; i<4; ++i) {
            int newX = x + nextStep[i][0];
            int newY = y + nextStep[i][1];
            if( inAera( newX, newY) && !visited[newX][newY])
                if( planeDFS( board, word, strIndex+1, newX, newY))
                    return true;
        }
        visited[x][y] = false;

        return false;
    }

    bool inAera( int x, int y) {

        return ( x >= 0 && x < xUp) && ( y >= 0 && y < yUp);
    }
};

int main() {

    char b1[3][4] = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    vector<vector<char>> board1;
    for( int i = 0 ; i < 3 ; i ++ )
        board1.push_back(vector<char>(b1[i], b1[i] + sizeof(b1[i]) / sizeof(char)));

    int cases = 3;
    string words[3] = {"ABCCED" , "SEE" , "ABCB" };
    for( int i = 0 ; i < cases ; i ++ )
        if(Solution().exist(board1,words[i]))
            cout<<"found "<<words[i]<<endl;
        else
            cout<<"can not found "<<words[i]<<endl;

    // ---

    char b2[1][1] = {{'A'}};
    vector<vector<char>> board2;
    for(int i = 0 ; i < 3 ; i ++)
        board2.push_back(vector<char>(b2[i],b2[i]+sizeof(b2[i])/sizeof(char)));

    if(Solution().exist(board2,"AB"))
        cout<<"found AB"<<endl;
    else
        cout<<"can not found AB"<<endl;

    return 0;
}
