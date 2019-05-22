/// https://leetcode.com/problems/4sum-ii/description/
/// Author : Fei
/// Time   : May-21-2019

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;

/// Using Hash Map
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {

        unordered_map<int,int> unMap;
        int res = 0;
        for( int i : A)
            for( int j : B)
                unMap[ i + j] ++;
        for( int k : C)
            for( int l : D)
                if( unMap.count( -k - l))
                    res += unMap[ -k - l];

        return res;
    }
};

int main() {

    int a[] = {1, 2};
    int b[] = {-2, -1};
    int c[] = {-1, 2};
    int d[] = {0, 2};
    vector<int> a_vec = vector<int>(a, a + sizeof(a)/sizeof(int));
    vector<int> b_vec = vector<int>(b, b + sizeof(b)/sizeof(int));
    vector<int> c_vec = vector<int>(c, c + sizeof(c)/sizeof(int));
    vector<int> d_vec = vector<int>(d, d + sizeof(d)/sizeof(int));

    cout << Solution().fourSumCount(a_vec, b_vec, c_vec, d_vec) << endl;

    return 0;
}

