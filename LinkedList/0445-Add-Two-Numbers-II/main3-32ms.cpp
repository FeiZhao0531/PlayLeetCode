/// https://leetcode.com/problems/add-two-numbers-ii/
/// Author : Fei
/// Time   : Jun-4-2019

#include <iostream>
#include "../SingleLinkedList.h"
#include "../SingleLinkedList.cpp"
#include <vector>

using namespace std;

class Solution {
    // 3 stack  32ms 14.4M
    ListNode* addTwoNumbers3(ListNode* l1, ListNode* l2) {

        stack<int> stk1, stk2;
        while( l1) {
            stk1.push( l1->val);
            l1 = l1->next;
        }
        while( l2) {
            stk2.push( l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        stack<int> sumStk;
        while( !stk1.empty() || !stk2.empty() || carry) {
            int sum = carry;
            if( !stk1.empty()) {
                sum += stk1.top();
                stk1.pop();
            }
            if( !stk2.empty()) {
                sum += stk2.top();
                stk2.pop();
            }
            carry = sum / 10;
            sumStk.push( sum % 10);
        }

        ListNode* sumHead = new ListNode(0);
        ListNode* curr = sumHead;
        while( !sumStk.empty()) {
            ListNode* sumNode = new ListNode( sumStk.top());
            sumStk.pop();
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
