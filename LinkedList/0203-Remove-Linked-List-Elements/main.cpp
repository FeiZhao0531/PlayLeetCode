/// Source : https://leetcode.com/problems/remove-linked-list-elements/description/
/// Author : Fei
/// Time   : Jun-4-2019

#include <iostream>
#include "../SingleLinkedList.h"
#include "../SingleLinkedList.cpp"

using namespace std;

/// Linear Scan with dummy head
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;
        while( curr->next) {
            if( curr->next->val == val) {
                ListNode* delNode = curr->next;
                curr->next = delNode->next;
                delete delNode;
            }

            else
                curr = curr->next;
        }
        ListNode* res = dummy->next;
        delete dummy;
        dummy = NULL;

        return res;
    }
};


int main() {

    int arr[] = {1, 2, 6, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(int);

    SingleLinkedList mysinglelinkedlist;
    ListNode* head = mysinglelinkedlist.createSingleLinkedList(arr, n);
    mysinglelinkedlist.printSingleLinkedList(head);

    Solution().removeElements(head, 6);
    mysinglelinkedlist.printSingleLinkedList(head);

    mysinglelinkedlist.deleteSingleLinkedList(head);

    return 0;
}
