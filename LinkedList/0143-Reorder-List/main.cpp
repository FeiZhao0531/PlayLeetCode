/// Source : https://leetcode.com/problems/reorder-list/
/// Author : Fei
/// Time   : Jun-5-2019

#include <iostream>
#include "../SingleLinkedList.h"
#include "../SingleLinkedList.cpp"

/// Reverses List and merge two lists
///
/// Time Complexity: O(N)
/// Space Complexity: O(1)
class Solution {
public:
    void reorderList(ListNode* head) {

        if( !head || !(head->next))
            return;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while( fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;

        head = mergeList( head, reverseList( fast));
        return;
    }

private:
    ListNode* mergeList( ListNode* l1, ListNode* l2) {

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while( l1 && l2) {
            curr->next = l1;
            l1 = l1->next;
            curr = curr->next;

            curr->next = l2;
            l2 = l2->next;
            curr = curr->next;
        }
        if( l1)
            curr->next = l1;
        ListNode* res = dummy->next;
        delete dummy;
        dummy = NULL;

        return res;
    }

    ListNode* reverseList( ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;
        while( curr) {
            ListNode* aftr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = aftr;
        }

        return prev;
    }
};

int main()
{
    int arr1[] = {1,2,3,4,5};
    //int arr1[] = {1,1};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);

    SingleLinkedList mysinglelinkedlist;
    ListNode* l1 = mysinglelinkedlist.createSingleLinkedList(arr1, n1);
    mysinglelinkedlist.printSingleLinkedList(l1);

    Solution().reorderList(l1);

    mysinglelinkedlist.printSingleLinkedList(l1);
    mysinglelinkedlist.deleteSingleLinkedList(l1);
    //system("pause");
    return 0;
}
