/// Source : https://leetcode.com/problems/palindrome-linked-list/description/
/// Author : Fei
/// Time   : Jun-5-2019

#include <iostream>
#include "../SingleLinkedList.h"
#include "../SingleLinkedList.cpp"

/// Two Pointers to Reverse and Traverse
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool isPalindrome(ListNode* head) {

        if( !head || !( head->next))
            return true;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while( fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        slow = head;
        fast = reverseList( fast);
        while( fast) {
            if( slow->val != fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }

        return true;
    }

private:
    ListNode* reverseList( ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;
        while( curr) {
            ListNode* aftr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = aftr;
        }
        return prev;
    }
};

int main()
{
    int arr1[] = {1,2,3,2,1};
    //int arr1[] = {1,1};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);

    SingleLinkedList mysinglelinkedlist;
    ListNode* l1 = mysinglelinkedlist.createSingleLinkedList(arr1, n1);
    mysinglelinkedlist.printSingleLinkedList(l1);

    if( Solution().isPalindrome(l1) )
        cout<<"True"<<endl;
    else cout<<"False"<<endl;
    system("pause");

    mysinglelinkedlist.printSingleLinkedList(l1);
    mysinglelinkedlist.deleteSingleLinkedList(l1);
    return 0;
}
