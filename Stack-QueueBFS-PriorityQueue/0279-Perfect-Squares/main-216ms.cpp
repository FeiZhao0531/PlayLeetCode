/// Source : https://leetcode.com/problems/perfect-squares/description/
/// Author : Fei
/// Time   : Jun-11-2019

#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>

using namespace std;

/// BFS without memory record
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int numSquares(int n) {

        assert( n > 0);
        queue< pair<int,int> > q;  // <int,int> : < the left part of n, depth>
        q.push( make_pair( n, 0));
        while( !q.empty()) {
            n = q.front().first;
            int depth = q.front().second;
            q.pop();
            for( int i=1; n - i * i >= 0; ++i) {
                if( n - i * i == 0)
                    return depth + 1;
                q.push( make_pair( n - i * i, depth + 1));
            }
        }

        //throw invalid_argument(" No solution");
        return -1;
    }
};

int main() {

    cout << Solution().numSquares(12) << endl;
    cout << Solution().numSquares(13) << endl;

    return 0;
}
