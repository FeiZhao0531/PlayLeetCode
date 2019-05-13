/// Source : https://leetcode.com/problems/spiral-matrix/description/
/// Author : Fei
/// Time   : May-13-2019

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n*m)
/// Space Complexity: O(n*m)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> res;
        if( matrix.size() == 0)
            return res;
        int row_begin = 0, row_end = matrix.size() - 1;
        int col_begin = 0, col_end = matrix[0].size() - 1;

        while( row_begin <= row_end && col_begin <= col_end) {
            // top edge
            for( int i=col_begin; i<=col_end; ++i)
                res.push_back( matrix[row_begin][i]);
            row_begin ++;
            if( row_begin > row_end)
                break;

            // right edge
            for( int i=row_begin; i<=row_end; ++i)
                res.push_back( matrix[i][col_end]);
            col_end --;
            if( col_begin > col_end)
                break;

            // bottom edge
            for( int i=col_end; i>=col_begin; --i)
                res.push_back( matrix[row_end][i]);
            row_end --;
            if( row_begin > row_end)
                break;

            // left edge
            for( int i=row_end; i>=row_begin; --i)
                res.push_back( matrix[i][col_begin]);
            col_begin ++;
            if( col_begin > col_end)
                break;
        }

        return res;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<vector<int>> matrix1 = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    print_vec(Solution().spiralOrder(matrix1));

    return 0;
}
