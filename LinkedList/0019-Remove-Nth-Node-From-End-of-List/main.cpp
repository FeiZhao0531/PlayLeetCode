/// Source : https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
/// Author : Fei
/// Time   : Jun-5-2019

#include <iostream>
#include "../SingleLinkedList.h"
#include "../SingleLinkedList.cpp"

/// Two Pointers - One Pass Algorithm
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if( !head)
            return head;
        ListNode* slow = head;
        ListNode* fast = head;
        for( int i=0; i<n; i++) {
            //assert( fast != NULL);
            fast = fast->next;
        }
        if( !fast)
            return head->next;
        while( fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        delNode = NULL;

        return head;
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

    ListNode* head = Solution().removeNthFromEnd(l1,2);

    mysinglelinkedlist.printSingleLinkedList(head);
    mysinglelinkedlist.deleteSingleLinkedList(head);
    //system("pause");
    return 0;
}
