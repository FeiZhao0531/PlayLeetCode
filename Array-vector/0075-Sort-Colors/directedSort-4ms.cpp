///  source: https://leetcode.com/problems/sort-colors/
///  author: Fei Zhao
///  creating time: May-8-2019

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {

//  Time complexity: O( nlogn)
//  Space complexity: O( 1)
public:
    void sortColors(vector<int>& nums) {

        sort( nums.begin(), nums.end());
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
