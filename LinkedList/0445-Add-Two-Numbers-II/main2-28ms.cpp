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
    //2. ΩË÷˙’ª  28ms 12.1M
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        vector<int> vec1, vec2;
        while( l1) {
            vec1.push_back( l1->val);
            l1 = l1->next;
        }
        while( l2) {
            vec2.push_back( l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        vector<int> sumVec;
        while( !vec1.empty() || !vec2.empty() || carry) {
            int sum = carry;
            if( !vec1.empty()) {
                sum += vec1.back();
                vec1.pop_back();
            }
            if( !vec2.empty()) {
                sum += vec2.back();
                vec2.pop_back();
            }
            carry = sum / 10;
            sumVec.push_back( sum % 10);
        }

        ListNode* sumHead = new ListNode(0);
        ListNode* curr = sumHead;
        while( !sumVec.empty()) {
            ListNode* sumNode = new ListNode( sumVec.back());
            sumVec.pop_back();
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

    ListNode* head = Solution().addTwoNumbers(l1,l2);
    mysinglelinkedlist.printSingleLinkedList(head);
    mysinglelinkedlist.deleteSingleLinkedList(head);
    //system("pause");
    return 0;
}
