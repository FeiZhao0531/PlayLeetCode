/// Source : https://leetcode.com/problems/top-k-frequent-elements/description/
/// Author : Fei
/// Time   : Jun-12-2019

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cassert>

using namespace std;

/// Sort the frequency in unordered_map
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> unMap;
        for( int num : nums)
            unMap[ num] ++;
        assert( k <= unMap.size() && k >= 1);

        vector< pair<int,int> > record;
        auto iter = unMap.begin();
        for( ; iter != unMap.end(); ++iter)
            record.push_back( make_pair( iter->first, iter->second));
        auto cmp = []( const pair<int,int>& p1, const pair<int,int>& p2){
            return p1.second > p2.second;
        };
        sort( record.begin(), record.end(), cmp);

        vector<int> res;
        for( int i=0; i<k; ++i)
            res.push_back( record[i].first);
        return res;
    }
};

int main() {

    int nums[] = {1, 1, 1, 2, 2, 3};
    vector<int> vec(nums, nums + sizeof(nums)/sizeof(int));
    int k = 2;

    vector<int> res = Solution().topKFrequent(vec, 2);
    for( int i = 0 ; i < res.size() ; i ++ )
        cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}
