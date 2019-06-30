/// Source : https://leetcode.com/problems/combinations/description/
/// Author : Fei
/// Time   : Jun-28-2019

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Naive Recursive
/// Time Complexity: O(k * C(n, k))
/// Space Complexity: O(k)
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {

        res.clear();
        assert( k >= 1 && k <= n);
        assert( n > 0);
        this->n = n;
        this->k = k;
        vector<int> tmp;
        findCombination( 1, tmp);

        return res;
    }
private:
    vector< vector<int> > res;
    int n;
    int k;

    void findCombination( int low, vector<int>& tmp) {

        if( tmp.size() == k) {
            res.push_back( tmp);
            return;
        }

        for( int i=low; i <= n - ( k - tmp.size()) + 1; ++i) {
            tmp.push_back( i);
            findCombination( i+1, tmp);
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

    vector<vector<int>> res = Solution().combine(4,2);
    for( int i = 0 ; i < res.size() ; i ++ )
        print_vec(res[i]);
    return 0;
}
