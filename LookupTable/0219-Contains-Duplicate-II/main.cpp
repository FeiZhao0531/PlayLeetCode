/// Source : https://leetcode.com/problems/contains-duplicate-ii/description/
/// Author : Fei
/// Time   : May-22-2019

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/// Using Hash Set
/// Time Complexity: O(n)
/// Space Complexity: O(k)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        if( nums.size() <= 1 || k <= 0)
            return false;
        unordered_set<int> unSet;
        for( int i=0; i<nums.size(); ++i)
            if( unSet.count( nums[i]))
                return true;
            unSet.insert( nums[i]);
            if( unSet.size() == k + 1)
                unSet.erase( nums[ i - k]);
        }

        return false;
    }
};


void print_bool(bool b){
    cout << (b ? "True" : "False") << endl;
}

int main() {

    vector<int> nums = {1, 2, 3, 1};
    int k = 3;

    print_bool(Solution().containsNearbyDuplicate(nums, k));

    return 0;
}
