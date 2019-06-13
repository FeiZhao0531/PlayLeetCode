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

/// Merge List One by One
/// Time Complexity: O(k*n), where k is len(lists) and n is the nodes number
/// Space Complexity: O(1)
class Solution {
public:

    ListNode* mergeKLists2(vector<ListNode*>& lists) {

        ListNode* head = NULL;
        for( int i=0; i<lists.size(); ++i)
            if( lists[i] != NULL)
                head = mergeTwoLists( head, lists[i]);

        return head;
    }

private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode* head = new ListNode(0);
        ListNode* cur = head;
        while( l1 && l2) {
            if( l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
            cur->next = NULL;
        }
        if( !l1)
            cur->next = l2;
        if( !l2)
            cur->next = l1;

        ListNode* res = head->next;
        delete head;
        head = NULL;
        return res;
    }
};


int main() {

    return 0;
}
