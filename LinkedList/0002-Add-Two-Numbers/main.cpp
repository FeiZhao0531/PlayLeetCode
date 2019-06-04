/// Source : https://leetcode.com/problems/add-two-numbers/description/
/// Author : Fei
/// Time   : Jun-4-2019

#include "../SingleLinkedList.h"
#include "../SingleLinkedList.cpp"
#include <cassert>

using namespace std;

class Solution
{
public:
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        assert( l1 && l2);
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
            curr->next = new ListNode( sum % 10);
            curr = curr->next;
        }
        ListNode* res = sumHead->next;
        delete sumHead;
        sumHead = NULL;

        return res;
    }
};

int main()
{
    int arr1[] = {2,4,3,1};
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

    ListNode* head = Solution().addTwoNumbers(l1,l2);
    mysinglelinkedlist.printSingleLinkedList(head);
    mysinglelinkedlist.deleteSingleLinkedList(head);
    return 0;
}
