///  source: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
///  author: Fei Zhao
///  creating time: May-9-2019

#include <iostream>
#include <vector>
#include <cassert>
#include <exception>

using namespace std;

class Solution {

// Two pointers
// Time Complexity: O( n)
// Space Complexity: O(1)
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int l = 0, r = numbers.size() - 1;
        vector<int> res;
        while( l < r) {
            int sum = numbers[l] + numbers[r];
            if( sum == target) {
                res.push_back( l + 1);
                res.push_back( r + 1);
                return res;
            }
            else if( sum < target)
                ++ l;
            else
                -- r;
        }

        throw invalid_argument(" No Solution!");
    }
};

void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    int nums[] = {2, 7, 11, 15};
    vector<int> vec(nums, nums + sizeof(nums) / sizeof(int));
    int target = 10;
    printVec(Solution().twoSum(vec, target));

    return 0;
}
