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

//  Go through the vector once, the best choice
//  Time complexity: O( nlogn)
//  Space complexity: O( 1)
    void sortColors(vector<int>& nums) {

        int l = 0, i = 0, r = nums.size() - 1;
        // nums[0,l) = 0, nums[l, i-1] = 1, nums(r,nums.size-1] = 2;
        while( i <= r) {
            if( nums[i] == 0) {
                swap( nums[i], nums[l]);
                l ++;
                i ++;
            }
            else if( nums[i] == 2) {
                swap( nums[i], nums[r]);
                r --;
            }
            else {
                assert( nums[i] == 1)
                i ++;
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
