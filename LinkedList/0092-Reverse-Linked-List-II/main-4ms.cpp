/// Source : https://leetcode.com/problems/reverse-linked-list-ii/description/
/// Author : Fei
/// Time   : Jun-4-2019

#include <iostream>
#include "../SingleLinkedList.h"
#include "../SingleLinkedList.cpp"

using namespace std;

class Solution{
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* flag = dummy;
        for(int i=1; i<m; ++i)
            flag = flag->next;
        ListNode* pre = flag->next;
        ListNode* cur = pre->next;
        for(int i=m; i<n; ++i){
            ListNode* aft = cur->next;
            cur->next = pre;
            pre = cur;
            cur = aft;
        }
        flag->next->next = cur;
        flag->next = pre;
        ListNode* res = dummy->next;
        delete dummy;
        dummy = NULL;

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

    ListNode* head2 = Solution().reverseBetween(head,2,4);
    mysinglelinkedlist.printSingleLinkedList(head2);
    mysinglelinkedlist.deleteSingleLinkedList(head2);
    //system("pause");
    return 0;
}
