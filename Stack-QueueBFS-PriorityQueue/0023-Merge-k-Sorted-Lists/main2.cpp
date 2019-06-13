/// Source : https://leetcode.com/problems/merge-k-sorted-lists/description/
/// Author : Fei
/// Time   : Jun-12-2019

#include <iostream>
#include <vector>
#include <cassert>
#include <queue>

using namespace std;

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/// Using Priority Queue to compare each ListNode
/// Time Complexity: O(nlogk) where k is len(lists) and n is the nodes number
/// Space Complexity: O(1)
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode* dummy = new ListNode( -1);
        ListNode* curr = dummy;
        auto cmp = []( const ListNode* a, const ListNode* b) { return a->val > b->val;};
        priority_queue< ListNode*, vector< ListNode*>, decltype( cmp) > pq( cmp);

        for( int i=0; i<lists.size(); ++i)
            if( lists[i])
                pq.push( lists[i]);

        while( !pq.empty()) {
            ListNode* mini = pq.top();
            pq.pop();
            if( mini->next)
                pq.push( mini->next);
            curr->next = mini;
            curr = curr->next;
            curr->next = NULL; // not matters
        }
        ListNode* res = dummy->next;
        delete dummy;
        dummy = NULL;

        return res;
    }
};


int main() {

    return 0;
}
