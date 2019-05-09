///  source: https://leetcode.com/problems/sort-colors/
///  author: Fei Zhao
///  creating time: May-8-2019

#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:

//  Go through the vector twice
//  Time complexity: O( nlogn)
//  Space complexity: O( 1)
    void sortColors(vector<int>& nums) {

        int counts[3] = { 0};
        for( int i=0; i<nums.size(); ++i) {
            assert( nums[i] >= 0 && nums[i] <= 2);
            counts[ nums[i]] ++;
        }

        int index = 0;
        for( int i=0; i<3; ++i) {
            for( int j=0; j<counts[i]; ++j) {
                nums[index] = i;
                index ++;
            }
        }

        return;
    }
};

int main()
{
    int arr[] = { 2,0,2,1,1,0};
    vector<int> nums( arr, arr+sizeof(arr)/sizeof(int));
    Solution().sortColors( nums);
    for( vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
        cout<<*iter<<", ";
    cout<<endl;
    getchar();
    return 0;
}
