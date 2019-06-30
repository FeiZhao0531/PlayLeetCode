/// Source : https://leetcode.com/problems/subsets-ii/
/// Author : Fei
/// Time   : Jun-30-2019

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Recursive
/// Time Complexity: O(k * C(n, k))
/// Space Complexity: O(k)
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        res.clear();
        res.push_back( vector<int>());
        if( nums.empty()) return res;

        sort( nums.begin(), nums.end());
        vector<int> tmp; // temporary vector to contain nums elements
        findSubsetWithDup( nums, 0, tmp);

        return res;
    }
private:
    vector< vector<int> > res;
    vector<bool> visited;

    void findSubsetWithDup( const vector<int>& nums, int pt, vector<int>& tmp) {

        if( pt == nums.size()) return;

        for( int i=pt; i<nums.size(); ++i) {
            if( i > pt && nums[i] == nums[i-1]) continue;
            tmp.push_back( nums[i]);
            res.push_back( tmp);
            findSubsetWithDup( nums, i+1, tmp);
            tmp.pop_back();
        }
    }
};


void print2DVec(const vector< vector<int> >& vec){

    auto iter = vec.begin();
    for( ; iter != vec.end(); ++iter) {
        for( int n : *iter)
            cout << n << ", ";
        cout << endl;
    }
    cout << " Print Complete." << endl << endl;
}

int main() {

    vector<int> input{ 0, 0, 1, 1};
    vector<vector<int>> res = Solution().subsetsWithDup( input);
    print2DVec( res);
    return 0;
}
