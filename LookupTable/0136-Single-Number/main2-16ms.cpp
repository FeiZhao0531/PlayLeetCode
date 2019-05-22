/// Source : https://leetcode.com/problems/single-number/
/// Author : Fei
/// Time   : May-16-2019

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>
using namespace std;

/// Using hashtable to find the one
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        unordered_set<int> unSet;
        for( int e : nums) {
            if( unSet.count( e) != 0) {
                unSet.erase( e);
                continue;
            }
            unSet.insert( e);
        }

        return *(unSet.begin());
    }
};


int main() {

    vector<int> nums = {0, 0, 1, 1, 2};
    cout << Solution().singleNumber(nums) << endl;

    return 0;
}
