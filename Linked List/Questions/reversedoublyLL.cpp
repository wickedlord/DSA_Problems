#include<iostream>
#include "NodeForDoublyLL.cpp"
using namespace std;

void reverseLL (Node* &head, Node* &tail, Node* back, Node* curr) {
    if ((curr==NULL) || ((curr->next==NULL) && (curr->prev=NULL))) {
        return;
    }
    tail = head;
    while (curr!=NULL) {
        curr->prev = curr->next;
        curr->next = back;
        back = curr;
        curr=curr->prev;
    }
    head = back;
}

int main () {
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,10);
    print(head,tail);

    Node* back = NULL;
    Node* curr = head;
    reverseLL(head, tail, back, curr);
    print(head,tail);
}