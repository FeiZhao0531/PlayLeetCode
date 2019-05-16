/// Source : https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
/// Author : Fei
/// Time   : May-14-2019

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/// Using Hash Map
/// Time Complexity: O(len(nums1) + len(nums2))
/// Space Complexity: O(len(nums1))
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        vector<int> res;
        unordered_map<int,int> unMap_nums1;
        for( int e : nums1)
            unMap_nums1[e] ++;

        for( int e : nums2) {
            if( unMap_nums1[e] != 0) {
                res.push_back(e);
                unMap_nums1[e] --;
            }
        }

        return res;
    }
};

void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    print_vec(Solution().intersect(nums1, nums2));

    return 0;
}
