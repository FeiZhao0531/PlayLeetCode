/// https://leetcode.com/problems/non-overlapping-intervals/
/// Author : Fei
/// Time   : Aug-4-2019

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// Greedy Algorithm based on ending point
/// Time Complexity:  O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        if( intervals.size() == 0)
            return 0;

        auto cmp = [](const vector<int>& l1, const vector<int>& l2){

            if( l1[1] != l2[1])
                return l1[1] < l2[1];

            return l1[0] < l2[0];
        };

        sort( intervals.begin(), intervals.end(), cmp);

        int res = 1, pre = 0;
        for( int i=1; i<intervals.size(); ++i ){
            if( intervals[i][0] >= intervals[pre][1]) {
                res ++;
                pre = i;
            }
        }

        return intervals.size() - res;
    }
};

int main() {

    vector<vector<int>> intervals1{ { 1, 2}, { 2, 3}, { 3, 4}, { 1, 3}};
    cout << Solution().eraseOverlapIntervals( intervals1) << endl;
    return 0;
}
