#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H
#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class SingleLinkedList
{
    public:
        SingleLinkedList();
        ~SingleLinkedList();
        ListNode* createSingleLinkedList(int arr[], int n);
        void printSingleLinkedList(ListNode* head);
        void deleteSingleLinkedList(ListNode* head);

    protected:

    private:

};

#endif // SINGLELINKEDLIST_H
