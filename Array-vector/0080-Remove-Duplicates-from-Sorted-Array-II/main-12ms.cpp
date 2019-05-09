///  https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
///  author: Fei Zhao
///  creating time: May-5-2019

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:

//  Time complexity: O( n)
//  Space complexity: O( 1)
    int removeDuplicates(vector<int>& nums) {

        if( nums.size() <= 1)
            return nums.size();

        int index = 0, counts = 1; // nums[0, index] contains the elements we need
        for( int i=1; i<nums.size(); ++i) {
            if( nums[i] != nums[index]) {
                ++ index;
                nums[index] = nums[i];
                counts = 1;
            }
            else if( counts < 2) {
                ++ index;
                nums[index] = nums[i];
                ++ counts;
            }
            else
                ++ counts;
        }

        return index + 1;
    }
};

int main()
{
    int arr[] = {0,0,1,1,1,2,2,3,3,4};
    vector<int> nums( arr, arr+sizeof(arr)/sizeof(int));
    cout<<Solution().removeDuplicates( nums)<<endl;
    return 0;
}
