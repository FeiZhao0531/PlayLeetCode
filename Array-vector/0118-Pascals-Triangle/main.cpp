/// Source : https://leetcode.com/problems/pascals-triangle/description/
/// Author : Fei
/// Time   : May-13-2019

#include <iostream>
#include <vector>

using namespace std;


/// Simulation (Dynamic Programming)
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> res;
        if(numRows <= 0)
            return res;

        res.push_back({1});
        for(int i = 1 ; i < numRows ; i ++){
            vector<int> row;
            row.push_back(1);
            for(int j = 1 ; j < i ; j ++)
                row.push_back(res[i-1][j-1] + res[i-1][j]);
            row.push_back(1);
            res.push_back(row);
        }
        return res;
    }
};

void print2D_vec( const vector<vector<int>>& vec) {

    for( auto iter=vec.begin(); iter != vec.end(); ++iter) {
        for( auto j_iter=(*iter).begin(); j_iter != (*iter).end(); ++j_iter)
            cout<< *j_iter << "  ";
        cout<<endl;
    }

    return;
}

int main() {

    int numRows = 5;
    vector<vector<int>> res = Solution().generate( numRows);
    print2D_vec( res);
    return 0;
}
