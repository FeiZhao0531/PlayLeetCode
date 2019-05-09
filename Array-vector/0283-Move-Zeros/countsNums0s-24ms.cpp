///  source: https://leetcode.com/problems/move-zeroes/
///  author: Fei Zhao
///  creating time: May-6-2019

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {

//  Time complexity: O( n)
//  Space complexity: O( 1)
public:
    void moveZeroes(vector<int>& nums) {

        if( nums.size() <= 1)
            return;
        int index = 0;
        for( int i=0; i<nums.size(); ++i) {
            if( nums[i] != 0)
                nums[index ++] = nums[i];
        }
        for( ; index<nums.size(); ++index)
            nums[index] = 0;

        return;
    }
};

int main()
{
    int arr[] = { 7,0,6,0,1,4,2,0,3};
    vector<int> nums( arr, arr+sizeof(arr)/sizeof(int));
    Solution().moveZeroes( nums);
    for( vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
        cout<<*iter<<", ";
    cout<<endl;
    return 0;
}
