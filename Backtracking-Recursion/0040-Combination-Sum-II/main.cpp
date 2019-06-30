/// Source : https://leetcode.com/problems/combination-sum-ii/description/
/// Author : Fei
/// Time   : Junu-29-2019

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Backtrack
/// Time Complexity: O(n^n)
/// Space Complexity: O(target)
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort( candidates.begin(), candidates.end());
        if( candidates.empty() || target < candidates[0])
            return res;
        this->target = target;
        visited = vector<bool>( candidates.size(), false); // false : Non visited
        vector<int> tmp;
        findCombinationSum2( candidates, 0, 0, tmp);

        return res;
    }
private:
    int target;
    vector< vector<int> > res;
    vector<bool> visited;

    void findCombinationSum2( const vector<int>& candidates, int pt, int sum, vector<int>& tmp) {

        cout << "sum = " << sum << "  pt = " << pt << endl;
        if( sum == target) {
            res.push_back( tmp);
            return;
        }

        for( int i=pt; i<candidates.size(); ++i) {
            // cout << "  i = " << i << " newSum = " << sum + candidates[i] <<endl;
            if( i > 0 && candidates[i] == candidates[i-1] && !visited[i-1])
                continue;
            if( candidates[i] + sum > target) return;
            tmp.push_back( candidates[i]);
            visited[i] = true;
            findCombinationSum2( candidates, i+1, sum + candidates[i], tmp);
            tmp.pop_back();
            visited[i] = false;
        }
        // cout << endl << endl;
    }
};

void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> res = Solution().combinationSum2(candidates, 8);
    for(const vector<int>& a_res: res)
        print_vec(a_res);

    return 0;
}
