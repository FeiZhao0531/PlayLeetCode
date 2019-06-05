/// Source : https://leetcode.com/problems/two-sum/description/
/// Author : Fei
/// Time   : Jun-4-2019

#include <iostream>
#include "../SingleLinkedList.h"
#include "../SingleLinkedList.cpp"

/// Merge Sort Top Down
/// Time Complexity: O(nlogn)
/// Space Complexity: O(logn)
class Solution {
public:
    ListNode* sortList(ListNode* head) {

        if( !head || !(head->next))
            return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while( fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;

        return mergeTwoSortedList( sortList( head), sortList( fast));
    }

private:
    ListNode* mergeTwoSortedList( ListNode* l1, ListNode* l2) {

        if( !l1)
            return l2;
        if( !l2)
            return l1;

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while( l1 && l2) {
            if( l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if( l1)
            curr->next = l1;
        else
            curr->next = l2;

        //return dummy->next;
        ListNode* res = dummy->next;
        delete dummy;
        dummy = NULL;

        return res;
    }
};

int main()
{
    int arr1[] = {5,4,3,2,1};
    //int arr1[] = {1,1};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);

    SingleLinkedList mysinglelinkedlist;
    ListNode* l1 = mysinglelinkedlist.createSingleLinkedList(arr1, n1);
    mysinglelinkedlist.printSingleLinkedList(l1);

    ListNode* head = Solution().sortList(l1);
    mysinglelinkedlist.printSingleLinkedList(head);
    mysinglelinkedlist.deleteSingleLinkedList(head);
    //system("pause");
    return 0;
}
