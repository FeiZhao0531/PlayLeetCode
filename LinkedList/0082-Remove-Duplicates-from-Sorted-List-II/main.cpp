/// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
/// Author : Fei
/// Time   : Jun-4-2019

#include <iostream>
#include "../SingleLinkedList.h"
#include "../SingleLinkedList.cpp"

/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        int duplicate = 0;
        while( curr && curr->next) {
            if( curr->val == curr->next->val) {
                duplicate = curr->val;
                while( curr && curr->val == duplicate) {
                    ListNode* delNode = curr;
                    curr = curr->next;
                    delete delNode;
                    delNode = NULL;
                }
                prev->next = curr;
            }
            else {
                prev = prev->next;
                curr = curr->next;
            }
        }
        ListNode* res = dummy->next;
        delete dummy;

        return res;
    }
};

int main()
{
    int arr1[] = {1,2,3,3,3,4,4,5};
    //int arr1[] = {1,1};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);

    SingleLinkedList mysinglelinkedlist;
    ListNode* l1 = mysinglelinkedlist.createSingleLinkedList(arr1, n1);
    mysinglelinkedlist.printSingleLinkedList(l1);

    ListNode* head = Solution().deleteDuplicates(l1);
    mysinglelinkedlist.printSingleLinkedList(head);
    mysinglelinkedlist.deleteSingleLinkedList(head);
    //system("pause");
    return 0;
}
