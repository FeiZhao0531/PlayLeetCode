/// Source : https://leetcode.com/problems/perfect-squares/description/
/// Author : Fei
/// Time   : Jun-11-2019

#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>

using namespace std;

/// BFS with memory record
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int numSquares(int n) {

        assert( n > 0);
        queue< pair<int,int> > q;  // <int,int> : < the left part of n, depth>
        vector<bool> visited( n, false); // bool ( false: never been visited; true: already visited)
        q.push( make_pair( n, 0));
        while( !q.empty()) {
            n = q.front().first;
            int depth = q.front().second;
            q.pop();
            for( int i=1; n - i * i >= 0; ++i) {
                int a = n - i * i;
                if( a == 0)
                    return 1 + depth;
                if( !visited[a]) {
                    q.push( make_pair( a, 1 + depth));
                    visited[a] = true;
                }
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
