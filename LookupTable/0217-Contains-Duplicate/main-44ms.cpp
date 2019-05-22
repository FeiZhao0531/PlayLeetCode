/// Source : https://leetcode.com/problems/contains-duplicate/
/// Author : Fei
/// Time   : May-22-2019

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> record(nums.begin(), nums.end());
        return nums.size() == record.size() ? 0 : 1;
    }
};

void print_bool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    vector<int> vec = {0, 0, 1};
    print_bool(Solution().containsDuplicate(vec));

    return 0;
}
