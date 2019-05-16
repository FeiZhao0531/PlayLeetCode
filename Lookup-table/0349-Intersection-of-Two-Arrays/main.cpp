/// Source : https://leetcode.com/problems/intersection-of-two-arrays/description/
/// Author : Fei
/// Time   : May-14-2019

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/// Hash Set
/// Time complexity: O(len(nums1) + len(nums2))
/// Space Complexity: O(len(nums1))
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> nums1Set( nums1.begin(), nums1.end());
        vector<int> res;

        for( int e : nums2) {
            if( nums1Set.find(e) != nums1Set.end()) {
                res.push_back(e);
                nums1Set.erase(e);
            }
        }

        return res;
    }
};

void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    int nums1[] = {1, 2, 2, 1};
    vector<int> vec1(nums1, nums1 + sizeof(nums1)/sizeof(int));

    int nums2[] = {2, 2};
    vector<int> vec2(nums2, nums2 + sizeof(nums2)/sizeof(int));

    printVec(Solution().intersection(vec1, vec2));

    return 0;
}
