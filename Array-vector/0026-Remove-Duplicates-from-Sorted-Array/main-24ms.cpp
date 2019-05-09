///  Source: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
///  author: Fei Zhao
///  creating time: May-6-2019

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

//  Time complexity: O( n)
//  Space complexity: O( 1)
    int removeDuplicates(vector<int>& nums) {

        if( nums.size() <= 1) // Due to the use of nums[0], we should check whether nums is empty
            return nums.size();

        int index = 0; // nums[0,index] Non-duplicated elements
        for( int i=1; i<nums.size(); ++i) {
            if( nums[i] != nums[index]) {
                if( i != index) {
                    index ++;
                    nums[index] = nums[i];
                }
                else
                    index ++;
            }
        }

        return index+1;
    }
};

int main()
{
    int arr[] = {0,0,1,1,1,2,2,3,3,4};
    vector<int> nums( arr, arr+sizeof(arr)/sizeof(int));
    cout<<Solution().removeDuplicates( nums)<<endl;
    getchar();
    return 0;
}
