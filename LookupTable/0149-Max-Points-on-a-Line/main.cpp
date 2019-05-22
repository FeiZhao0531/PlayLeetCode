/// Source : https://leetcode.com/problems/max-points-on-a-line/
/// Author : Fei
/// Time   : May-22-2019

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
#include <map>
using namespace std;

/// Using Hash Map
/// Using pair directly to record the slopes
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int maxPoints(vector< vector<int> >& points) {

        if( points.size() <= 2)
            return points.size();

        int res = 0;
        for( int i=0; i<points.size(); ++i) {
            map< pair<int,int>, int> recordMap; // save the same slope in hash map
            int samePoints = 1;
            for( int j=0; j<points.size(); ++j) {
                if( points[i][0] == points[j][0] && points[i][1] == points[j][1])
                    samePoints ++;
                else
                    recordMap[ slope( points[i], points[j])] ++;
            }
            res = max( res, samePoints); // for the case: [1,1],[1,1],[1,1]
            for( auto p : recordMap)
                res = max( res, p.second + samePoints);
        }

        return res;
    }

private:
    pair<int,int> slope( const vector<int>& p1, const vector<int>& p2) {

        int dx = p2[0] - p1[0], dy = p2[1] - p1[1];
        if( dx == 0)
            return make_pair( 0, 1);
        if( dy == 0)
            return make_pair( 1, 0);
        if( dx < 0) {
            dx = -dx;
            dy = -dy;
        }
        int gcdValue = gcd( abs(dx), abs(dy));

        return make_pair( dx/gcdValue, dy/gcdValue);
    }

    int gcd( int x, int y) {

        assert( x > 0 && y > 0);
        if( x < y)
            swap( x, y);
        int r = x % y;
        while( r != 0) {
            x = y;
            y = r;
            r = x % y;
        }

        return y;
    }
};

int main() {

    vector< vector<int> > pvec1;
    pvec1.push_back( {1, 1});
    pvec1.push_back( {1, 1});
    pvec1.push_back( {2, 3});
    pvec1.push_back( {3, 2});
    pvec1.push_back( {4, 1});
    pvec1.push_back( {1, 4});
    pvec1.push_back( {5, 3});

    cout<<Solution().maxPoints(pvec1)<<endl;

    return 0;
}
