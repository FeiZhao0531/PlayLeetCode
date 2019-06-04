/// Source : https://leetcode.com/problems/intersection-of-two-linked-lists/description/
/// Author : Fei
/// Time   : Jun-04-2019

#include "../SingleLinkedList.h"
#include "../SingleLinkedList.cpp"

using namespace std;

/// Time Complexity: O(m+n)
/// Space Complexity: O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int lenA = 0, lenB = 0;
        ListNode* currA = headA;
        ListNode* currB = headB;
        while( currA) {
            lenA ++;
            currA = currA->next;
        }
        while( currB) {
            lenB ++;
            currB = currB->next;
        }

        int differenceValue = lenA - lenB;
        currA = headA;
        currB = headB;
        if( differenceValue > 0) {
            while( differenceValue > 0) {
                currA = currA->next;
                differenceValue --;
            }
        }
        else {
            while( differenceValue < 0) {
                currB = currB->next;
                differenceValue ++;
            }
        }

        while( currA && currB) {
            if( currA == currB)
                return currA;
            else {
                currA = currA->next;
                currB = currB->next;
            }
        }

        return NULL;
    }
};


int main() {

    // It is a little difficult to write the test case ...
    return 0;
}
