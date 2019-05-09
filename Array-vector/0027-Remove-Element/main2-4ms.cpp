///  source: https://leetcode.com/problems/remove-element/
///  author: Fei Zhao
///  creating time: May-5-2019

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

//  Actually, this method is based on Two-pointers
//  Time complexity: O( n)
//  Space complexity: O( 1)
    int removeElement(vector<int>& nums, int val) {

        int index = 0; // nums[ index, i) = val
        for( int i=0; i<nums.size(); ++i) {
            if( nums[i] != val) {
                if( i != index)
                    swap( nums[i], nums[index ++]);
                else
                    index ++;
            }
        }

        return index;
    }
};

int main()
{
    int arr[] = {0,1,2,2,3,0,4,2};
    vector<int> nums( arr, arr+sizeof(arr)/sizeof(int));
    cout<<Solution().removeElement( nums, 2)<<endl;
    return 0;
}
