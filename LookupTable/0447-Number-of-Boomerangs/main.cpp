/// Source : https://leetcode.com/problems/number-of-boomerangs/description/
/// Author : Fei
/// Time   : MAy-21-2019

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
#include <stdexcept>

using namespace std;

/// Using Hash Map
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {

        int res = 0;
        for( int i=0; i<points.size(); ++i) {
            unordered_map<int,int> unMap; // <int,int> : < dist**2, times>
            for( int j=0; j<points.size(); ++j) {
                if( i == j)
                    continue;
                unMap[ dist( points[i], points[j])] ++;
            }
            for( auto p : unMap)
                res += p.second * ( p.second - 1);
        }

        return res;
    }

private:
    int dist( const vector<int>& v1, const vector<int>& v2) {

        return ( ( v1[0] - v2[0])*( v1[0] - v2[0]) + ( v1[1] - v2[1])*( v1[1] - v2[1]));
    }
};

int main() {

    vector< vector<int> > vec;
    vec.push_back( { 0, 0});
    vec.push_back( { 1, 0});
    vec.push_back( { 2, 0});

    cout << Solution().numberOfBoomerangs(vec) << endl;

    return 0;
}
