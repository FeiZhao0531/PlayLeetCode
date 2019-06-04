/// https://leetcode.com/problems/add-two-numbers-ii/
/// Author : Fei
/// Time   : Jun-4-2019

#include <iostream>
#include "../SingleLinkedList.h"
#include "../SingleLinkedList.cpp"
#include <vector>

using namespace std;

class Solution {
public:
    // 1.反转链表，其余和002题相同
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        return reverseList( addTwoNumbersReverse( reverseList( l1), reverseList( l2)));
    }
private:
    ListNode* reverseList( ListNode* head) {

        ListNode* pre = NULL;
        ListNode* curr = head;
        while( curr) {
            ListNode* aft = curr->next;
            curr->next = pre;
            pre = curr;
            curr = aft;
        }

        return pre;
    }

    ListNode* addTwoNumbersReverse( ListNode* l1, ListNode* l2) {

        ListNode* sumHead = new ListNode(0);
        ListNode* curr = sumHead;
        int carry = 0;
        while( l1 || l2 || carry) {
            int sum = carry;
            if( l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if( l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            ListNode* sumNode = new ListNode( sum % 10);
            curr->next = sumNode;
            curr = curr->next;
        }
        ListNode* res = sumHead->next;
        delete sumHead;

        return res;
    }
};

int main()
{
    int arr1[] = {7,2,4,3};
    int arr2[] = {5,6,4};
//    int arr1[] = {0};
//    int arr2[] = {0};

    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    SingleLinkedList mysinglelinkedlist;
    ListNode* l1 = mysinglelinkedlist.createSingleLinkedList(arr1, n1);
    ListNode* l2 = mysinglelinkedlist.createSingleLinkedList(arr2, n2);
    mysinglelinkedlist.printSingleLinkedList(l1);
    mysinglelinkedlist.printSingleLinkedList(l2);

    ListNode* head = Solution().addTwoNumbers2(l1,l2);
    mysinglelinkedlist.printSingleLinkedList(head);
    mysinglelinkedlist.deleteSingleLinkedList(head);
    //system("pause");
    return 0;
}
