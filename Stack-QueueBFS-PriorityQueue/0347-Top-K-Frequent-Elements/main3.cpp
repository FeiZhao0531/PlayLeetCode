/// Source : https://leetcode.com/problems/top-k-frequent-elements/description/
/// Author : Fei
/// Time   : Jun-12-2019

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cassert>

using namespace std;

/// Priority Queue
/// Time Complexity: O(nlog(n-k))
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> unMap; // <key, frequency>
        for( int num : nums)
            unMap[ num] ++;
        int n = unMap.size();
        assert( k >= 1 && k <= n);

        priority_queue< pair<int,int> > pq; // < frequency, key>
        vector<int> res;
        auto iter = unMap.begin();
        for( ; iter != unMap.end(); ++iter) {
            pq.push( make_pair( iter->second, iter->first));
            if( pq.size() > n - k) {
                res.push_back( pq.top().second);
                pq.pop();
            }
        }

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
