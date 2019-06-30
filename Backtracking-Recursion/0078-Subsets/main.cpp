/// Source : https://leetcode.com/problems/subsets/
/// Author : Fei
/// Time   : Jun-30-2019

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Recursive
/// Time Complexity: O(2^n)
/// Space Complexity: O(2^n)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        res.clear();
        res.push_back( vector<int>());
        if( nums.empty())
            return res;
        vector<int> tmp; // temporary vector to contain elements
        findSubset( nums, 0, tmp);

        return res;
    }
private:
    vector< vector<int> > res;

    void findSubset( const vector<int>& nums, int pt , vector<int>& tmp) {

        if( pt == nums.size()) return;

        for( int i=pt; i<nums.size(); ++i) {
            tmp.push_back( nums[i]);
            res.push_back( tmp);
            findSubset( nums, i+1, tmp);
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

    vector<int> input{ 1,2,3};
    vector<vector<int>> res = Solution().subsets( input);
    print2DVec( res);
    return 0;
}
