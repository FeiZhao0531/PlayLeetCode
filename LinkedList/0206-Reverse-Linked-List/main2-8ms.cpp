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

        ListNode* prev = new ListNode(0);
        ListNode* curr = head;
        prev->next = curr;
        while( curr && curr->next) {
            ListNode* aftr = curr->next;
            curr->next = aftr->next;
            aftr->next = prev->next;
            prev->next = aftr;
        }
        ListNode* res = prev->next;
        delete prev;
        return res;
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
