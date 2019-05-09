///  source: https://leetcode.com/problems/move-zeroes/
///  author: Fei Zhao
///  creating time: May-6-2019

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:

// Two pointers to separate this Array
//  Time complexity: O( n)
//  Space complexity: O( 1)
    void moveZeroes(vector<int>& nums) {

        int index = 0; // nums[ index, i) = 0
        for( int i=0; i<nums.size(); ++i) {
            if( nums[i] != 0) {
                if( i != index)
                    swap( nums[i], nums[index ++]);
                else
                    index ++;
            }
        }
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
