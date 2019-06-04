/// Source : https://leetcode.com/problems/odd-even-linked-list/description/
/// Author : Fei
/// Time   : Jun-4-2019

#include <iostream>
#include "../SingleLinkedList.h"
#include "../SingleLinkedList.cpp"

using namespace std;

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) { // 16ms

        if( head == NULL || head->next == NULL)
            return head;

        ListNode* odd = head;
        ListNode* evenHead = head->next;
        ListNode* even = evenHead;
        while( even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;

        return head;
    }
};

int main()
{
    int arr[] = {2,1,3,5,6,4,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    SingleLinkedList mysinglelinkedlist;
    ListNode* head = mysinglelinkedlist.createSingleLinkedList(arr, n);
    mysinglelinkedlist.printSingleLinkedList(head);

    ListNode* head2 = Solution().oddEvenList(head);
    mysinglelinkedlist.printSingleLinkedList(head2);
    mysinglelinkedlist.deleteSingleLinkedList(head2);
    //system("pause");
    return 0;
}
