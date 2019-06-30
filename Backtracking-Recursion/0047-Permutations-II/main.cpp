/// Source : https://leetcode.com/problems/permutations-ii/description/
/// Author : Fei
/// Time   : Jun-29-2019

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// Most Naive Recursive
/// Time Complexity: O(n^n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        if( nums.empty())
            return res;

        vector<int> tmp;
        visited = vector<bool>( nums.size(), false);
        sort( nums.begin(), nums.end());
        findPermutation( nums, tmp);

        return res;
    }
private:
    vector< vector<int> > res;
    vector<bool> visited;

    void findPermutation( const vector<int>& nums, vector<int>& tmp) {

        if( tmp.size() == nums.size()) {
            res.push_back( tmp);
            return;
        }

        for( int i=0; i<nums.size(); ++i) {
            if( i > 0 && nums[i] == nums[i-1] && !visited[i-1])
                continue;
            if( !visited[i]) {
                tmp.push_back( nums[i]);
                visited[i] = true;
                findPermutation( nums, tmp);
                tmp.pop_back();
                visited[i] = false;
            }
        }
    }
};


void print2DVec(const vector< vector<int> >& vec){

    auto iter = vec.begin();
    for( ; iter != vec.end(); ++iter) {
        for( int n : *iter)
            cout << n << "  ";
        cout << endl;
    }
    cout << " Print Complete " << endl << endl;
}

int main() {

    vector<int> nums1 = {1, 1, 2};
    vector<vector<int>> res1 = Solution().permuteUnique(nums1);
    print2DVec( res1);

    vector<int> nums2 = {2, 2, 1, 1};
    vector<vector<int>> res2 = Solution().permuteUnique(nums2);
    print2DVec( res2);
    return 0;
}
