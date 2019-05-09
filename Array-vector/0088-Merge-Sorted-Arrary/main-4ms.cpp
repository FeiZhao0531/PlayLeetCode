///  source: https://leetcode.com/problems/merge-sorted-array/
///  author: Fei Zhao
///  creating time: May-8-2019

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:

//  Time complexity: O( n + m)
//  Space complexity: O( 1)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        assert( nums1.size() == m + n && nums2.size() == n);
        int index = m + n - 1, i = m - 1, j = n - 1;
        while( i >= 0 && j >= 0) {
            if( nums1[i] < nums2[j])
                nums1[k --] = nums2[j --];
            else
                nums1[k --] = nums1[i --];
        }
        while( j >= 0)
            nums1[k --] = nums2[j --];

        return;
    }
};

void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> nums1 = {1, 3, 5, 7};
    int m = nums1.size();

    vector<int> nums2 = {2, 4, 6};
    int n = nums2.size();

    for( int i = 0 ; i < nums2.size() ; i ++ )
        nums1.push_back(0);

    Solution().merge(nums1, m, nums2, n);
    printVec(nums1);

    return 0;
}
