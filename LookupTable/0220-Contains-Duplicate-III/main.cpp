/// Source : https://leetcode.com/problems/contains-duplicate-iii/description/
/// Author : Fei
/// Time   : May-22-2019

#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <stdexcept>
#include <cmath>

using namespace std;

// Using Tree Set
// Time Complexity: O(nlogk)
// Space Complexity: O(k)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

        if( nums.size() <= 1 || k <= 0 || t < 0)
            return false;
        set<long long> iset;
        for( int i=0; i<nums.size(); ++i) {
            if( iset.lower_bound( (long long)nums[i] - t) != iset.end() &&
              *iset.lower_bound( (long long)nums[i] - t) <= (long long)nums[i] + t)
                return true;
            iset.insert( nums[i]);
            if( iset.size() > k)
                iset.erase( nums[ i - k]);
        }

        return false;
    }
};


void printBool(bool b){
    cout << (b ? "True" : "False") << endl;
}

int main() {

    int nums[] = {0, 2147483647};
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int));
    int k = 1;
    int t = 2147483647;

    printBool(Solution().containsNearbyAlmostDuplicate(vec, k, t));

    return 0;
}
