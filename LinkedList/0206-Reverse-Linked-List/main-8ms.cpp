/// Source : https://leetcode.com/problems/reverse-linked-list/description/
/// Author : Fei
/// Time   : Jun-4-2019

#include <iostream>
//#include "../SingleLinkedList.h"
#include "../SingleLinkedList.cpp"

using namespace std;

class Solution{
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur != NULL) {
            ListNode* next = cur->next;

            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

};

int main()
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    SingleLinkedList mysinglelinkedlist;
    ListNode* head = mysinglelinkedlist.createSingleLinkedList(arr, n);
    mysinglelinkedlist.printSingleLinkedList(head);

    ListNode* head2 = Solution().reverseList(head);
    mysinglelinkedlist.printSingleLinkedList(head2);
    mysinglelinkedlist.deleteSingleLinkedList(head2);
    //system("pause");
    return 0;
}
