/// Source : https://leetcode.com/problems/combination-sum/description/
/// Author : Fei
/// Time   : Jun-29-2019

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// Backtrack
/// Time Complexity: O(n^n)
/// Space Complexity: O(target)
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        sort( candidates.begin(), candidates.end());
        if( candidates.empty() || candidates[0] > target)
            return res;

        this->target = target;
        vector<int> tmp;
        findCombinationSum( candidates, 0, 0, tmp);

        return res;
    }
private:
    int target;
    vector< vector<int> > res;

    void findCombinationSum( const vector<int>& candidates, int pt, int sum, vector<int>& tmp) {

        if( sum == target) {
            res.push_back( tmp);
            return;
        }

        for( int i=pt; i<candidates.size(); ++i) {
            if( sum + candidates[i]> target)
                break;
            else { // sum + candidates[i] <= target
                tmp.push_back( candidates[i]);
                findCombinationSum( candidates, i, sum + candidates[i], tmp);
                tmp.pop_back();
            }
        }
    }
};

void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> candidates = {2, 3, 6, 7};
    vector<vector<int>> res = Solution().combinationSum(candidates, 7);
    for(const vector<int>& a_res: res)
        print_vec(a_res);

    return 0;
}
