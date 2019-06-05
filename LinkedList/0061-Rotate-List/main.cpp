/// Source : https://leetcode.com/problems/rotate-list/description/
/// Author : Fei
/// Time   : Jun-5-2019

#include <iostream>
#include "../SingleLinkedList.h"
#include "../SingleLinkedList.cpp"

/// Two Pointers
///
/// Time Complexity: O(N)
/// Space Complexity: O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        int len = lengthLinkedList( head);
        if( len <= 1)
            return head;
        int realK = k % len;
        if( realK == 0)
            return head;

        ListNode* slow = head;
        ListNode* fast = head;
        for( int i=0; i<realK; ++i)
            fast = fast->next;
        while( fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = head;
        ListNode* newHead = slow->next;
        slow->next = NULL;

        return newHead;
    }
private:
    int lengthLinkedList( ListNode* node) {

        int len = 0;
        while( node) {
            len ++;
            node = node->next;
        }

        return len;
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

    ListNode* head = Solution().rotateRight(l1,2);

    mysinglelinkedlist.printSingleLinkedList(head);
    mysinglelinkedlist.deleteSingleLinkedList(head);
    //system("pause");
    return 0;
}
