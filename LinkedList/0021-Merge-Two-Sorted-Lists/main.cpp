/// Source : https://leetcode.com/problems/merge-two-sorted-lists/description/
/// Author : Fei
/// Time   : Jun-4-2019

#include <iostream>
#include "../SingleLinkedList.h"
#include "../SingleLinkedList.cpp"

using namespace std;

/// Iterative
/// Time Complexity: O(len(l1) + len(l2))
/// Space Complexity: O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if( !l1)
            return l2;
        if( !l2)
            return l1;

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while( l1 && l2) {
            if( l1->val <= l2->val) {
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
        if( l2)
            curr->next = l2;
        ListNode* res = dummy->next;
        delete dummy;
        dummy = NULL;

        return res;
    }
};

int main()
{
    int arr1[] = {1,2,4};
    int arr2[] = {1,3,4};
//    int arr1[] = {0};
//    int arr2[] = {0};

    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    SingleLinkedList mysinglelinkedlist;
    ListNode* l1 = mysinglelinkedlist.createSingleLinkedList(arr1, n1);
    ListNode* l2 = mysinglelinkedlist.createSingleLinkedList(arr2, n2);
    mysinglelinkedlist.printSingleLinkedList(l1);
    mysinglelinkedlist.printSingleLinkedList(l2);

    ListNode* head = Solution().mergeTwoLists(l1,l2);
    mysinglelinkedlist.printSingleLinkedList(head);
    mysinglelinkedlist.deleteSingleLinkedList(head);
    //system("pause");
    return 0;
}
