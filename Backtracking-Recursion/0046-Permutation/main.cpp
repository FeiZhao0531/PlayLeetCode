/// Source : https://leetcode.com/problems/permutations/description/
/// Author : Fei
/// Time   : Jun-28-2019

#include <iostream>
#include <vector>
using namespace std;

/// DFS
/// Time Complexity: O(n^n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        if( nums.empty())
            return res;

        vector<int> tmp;
        visited = vector<bool>( nums.size(), false);
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

        for( int i=0; i<nums.size(); ++i)
            if( visited[i] == false) {
                tmp.push_back( nums[i]);
                visited[i] = true;
                findPermutation( nums, tmp);
                tmp.pop_back();
                visited[i] = false;
            }
    }
};


void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    int nums[] = {1, 2, 3};
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int) );

    vector<vector<int>> res = Solution().permute(vec);
    for(int i = 0 ; i < res.size() ; i ++)
        printVec(res[i]);

    return 0;
}
