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
// Time Complexity: O( nlogn)
// Space Complexity: O(1)
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        vector<int> res;
        for( int index=0; index<numbers.size(); ++index) {
            int rIndex = binarySearch( numbers, index+1, numbers.size()-1, target - numbers[index]);
            if( rIndex != -1) {
                res.push_back( index+1);
                res.push_back( rIndex+1);
                return res;
            }
        }

        throw invalid_argument("No Solution!");
    }

private:

    // in the range of nums[l,r] to find  "target - nums[index]"
    int binarySearch( const vector<int>& nums, int l, int r, int newTarget) {

        int i = l, j = r;
        while( i <= j) {
            int mid = i + ( j - i) / 2;
            if( nums[mid] == newTarget)
                return mid;
            else if( nums[mid] > newTarget)
                j = mid - 1;
            else
                i = mid + 1;
        }

        return -1;
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
    int target = 9;
    printVec(Solution().twoSum(vec, target));

    return 0;
}
