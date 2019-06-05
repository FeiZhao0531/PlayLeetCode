/// Source : https://leetcode.com/problems/insertion-sort-list/
/// Author : Fei
/// Time   : jun-4-2019

#include <iostream>
#include "../SingleLinkedList.h"
#include "../SingleLinkedList.cpp"

/// Time Complexity: O(n^2)
/// Space Compelxity: O(1)
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {

        if( !head || !(head->next))
            return head;
        ListNode* dummy = new ListNode(INT_MIN); // head of the sorted LinkedList
        ListNode* curr = head;
        while( curr) {
            ListNode* prev = dummy;
            ListNode* aftr = dummy->next;
            while( prev->next && curr->val > aftr->val) {
                prev = prev->next;
                aftr = aftr->next;
            }
            prev->next = curr;
            curr = curr->next;
            prev->next->next = aftr;
        }
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

    ListNode* head = Solution().insertionSortList(l1);
    mysinglelinkedlist.printSingleLinkedList(head);
    mysinglelinkedlist.deleteSingleLinkedList(head);
    //system("pause");
    return 0;
}
