/// Source : https://leetcode.com/problems/combination-sum-iii/description/
/// Author : Fei
/// Time   : Jun-30-2019

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {

        res.clear();
        if( n < k)
            return res;
        this->k = k;
        this->n = n;
        vector<int> tmp;
        findCombinationSum3( 0, 1, tmp);

        return res;
    }
private:
    int k;
    int n;
    vector< vector<int> > res;

    void findCombinationSum3( int sum, int pt, vector<int>& tmp) {

        if( tmp.size() > k) return;
        if( sum == n && tmp.size() == k) {
            res.push_back( tmp);
            return;
        }

        for( int i=pt; i<=9; ++i) {
            if( sum + i > n) return;
            tmp.push_back( i);
            findCombinationSum3( sum+i, i+1, tmp);
            tmp.pop_back();
        }
    }
};

void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<vector<int>> res1 = Solution().combinationSum3(3, 7);
    for(const vector<int>& a_res: res1)
        print_vec(a_res);

    cout << endl;

    vector<vector<int>> res2 = Solution().combinationSum3(3, 9);
    for(const vector<int>& a_res: res2)
        print_vec(a_res);

    return 0;
}
