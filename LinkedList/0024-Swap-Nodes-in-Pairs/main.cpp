/// Source : https://leetcode.com/problems/swap-nodes-in-pairs/description/
/// Author : Fei
/// Time   : Jun-4-2019

#include "../SingleLinkedList.h"
#include "../SingleLinkedList.cpp"
#include <iostream>

using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        if( !head || !(head->next))
            return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        while( prev->next && prev->next->next) {
            ListNode* curr = prev->next;
            ListNode* aftr = curr->next;

            curr->next = aftr->next;
            aftr->next = curr;
            prev->next = aftr;

            prev = curr;
        }
        ListNode* res = dummy->next;
        delete dummy;
        dummy = NULL;

        return res;
    }
};

int main()
{
    int arr1[] = {1,2,3,4,5,6,7};
    //int arr1[] = {1,1};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);

    SingleLinkedList mysinglelinkedlist;
    ListNode* l1 = mysinglelinkedlist.createSingleLinkedList(arr1, n1);
    mysinglelinkedlist.printSingleLinkedList(l1);

    ListNode* head = Solution().swapPairs(l1);
    mysinglelinkedlist.printSingleLinkedList(head);
    mysinglelinkedlist.deleteSingleLinkedList(head);
    //system("pause");
    return 0;
}
