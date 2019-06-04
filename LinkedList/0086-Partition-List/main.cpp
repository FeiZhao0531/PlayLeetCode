/// Source : https://leetcode.com/problems/partition-list/description/
/// Author : Fei
/// Time   : Jun-4-2019

#include <iostream>
#include "../SingleLinkedList.h"
#include "../SingleLinkedList.cpp"

using namespace std;

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        if( !head || !(head->next))
            return head;
        ListNode* smallerHead = new ListNode(0);
        ListNode* s = smallerHead;
        ListNode* greaterHead = new ListNode(0);
        ListNode* g = greaterHead;

        while( head) {
            if( head->val < x) {
                s->next = head;
                s = s->next;
            }
            else {
                g->next = head;
                g = g->next;
            }
            head = head->next;
        }
        s->next = greaterHead->next;
        g->next = NULL;
        ListNode* res = smallerHead->next;
        delete smallerHead;
        smallerHead = NULL;
        delete greaterHead;
        greaterHead = NULL;

        return res;
    }
};


int main()
{
    int arr[] = {1,4,3,2,5,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    SingleLinkedList mysinglelinkedlist;
    ListNode* head = mysinglelinkedlist.createSingleLinkedList(arr, n);
    mysinglelinkedlist.printSingleLinkedList(head);

    ListNode* head2 = Solution().partition(head,3);
    mysinglelinkedlist.printSingleLinkedList(head2);
    mysinglelinkedlist.deleteSingleLinkedList(head2);
    system("pause");
    return 0;
}
