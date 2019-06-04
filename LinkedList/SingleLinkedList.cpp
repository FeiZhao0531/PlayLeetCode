#include "SingleLinkedList.h"
#include <iostream>

using namespace std;

SingleLinkedList::SingleLinkedList()
{
}

SingleLinkedList::~SingleLinkedList()
{
    //dtor
}

ListNode* SingleLinkedList::createSingleLinkedList(int arr[], int n)
{
    if( n == 0 ) return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* curNode = head;
    for(int i=1; i<n; ++i) {
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }
    return head;
}

void SingleLinkedList::printSingleLinkedList(ListNode* head)
{
    ListNode* curNode = head;
    while(curNode != NULL){
        cout << curNode->val <<" -> ";
        curNode = curNode->next;
    }
    cout <<"NULL"<<endl;
    return;
}

void SingleLinkedList::deleteSingleLinkedList(ListNode* head)
{
    ListNode* curNode = head;
    while(curNode != NULL){
        ListNode* delNode = curNode;
        curNode = curNode->next;
        delete delNode;
        delNode = NULL;
    }
    return;
}
