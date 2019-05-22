/// Source : https://leetcode.com/problems/two-sum/description/
/// Author : Fei
/// Time   : May-20-2019

#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>

using namespace std;

/// Hash Table
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        assert( nums.size() >= 2);
        unordered_map< int, int> unMap;
        for( int i=0; i<nums.size(); ++i) {
            if( unMap.count( target - nums[i]) != 0)
                return {unMap[ target - nums[i]], i};
            else
                unMap[ nums[i]] = i;
        }

        throw invalid_argument("No Solution!");
    }
};


void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> nums = {2,11,7,5};
    int target = 9;
    printVec(Solution().twoSum(nums, target));

    return 0;
}
