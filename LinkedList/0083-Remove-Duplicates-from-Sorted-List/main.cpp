/// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-list/
/// Author : Fei
/// Time   : Jun-4-2019

#include <iostream>
#include "../SingleLinkedList.h"
#include "../SingleLinkedList.cpp"

using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if( !head)
            return head;
        ListNode* cur = head;
        while( cur->next) {
            if( cur->val == cur->next->val) {
                ListNode* delNode = cur->next;
                cur->next = cur->next->next;
                delete delNode;
            }
            else
                cur = cur->next;
        }
        return head;
    }
};

int main()
{
    int arr[] = { 1, 1, 2, 3, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    SingleLinkedList mysinglelinkedlist;
    ListNode* l = mysinglelinkedlist.createSingleLinkedList(arr, n);
    mysinglelinkedlist.printSingleLinkedList(l);

    ListNode* head = Solution().deleteDuplicates( l);
    mysinglelinkedlist.printSingleLinkedList(head);
    system("pause");
    return 0;
}
