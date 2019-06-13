/// Source : https://leetcode.com/problems/top-k-frequent-elements/description/
/// Author : Fei
/// Time   : Jun-12-2019

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cassert>

using namespace std;

/// Priority Queue, learned from liuyubobobo
/// Time Complexity: O(nlog(k))
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        assert(k > 0);

        // 统计每个元素出现的频率
        unordered_map<int,int> freq; // < key, frequency>
        for(int i = 0 ; i < nums.size() ; i ++ )
            freq[nums[i]] ++;

        assert(k <= freq.size());

        // 扫描freq,维护当前出现频率最高的k个元素
        // 在优先队列中,按照频率排序,所以数据对是 (频率,元素) 的形式，最小堆
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(unordered_map<int,int>::iterator iter = freq.begin();
            iter != freq.end(); iter ++ ){
            pq.push( make_pair( iter->second, iter->first));
            if( pq.size() > k)
                pq.pop();
        }

        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
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
