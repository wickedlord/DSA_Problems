#include <iostream>
#include "NodeForSinglyLL.cpp"
using namespace std;

Node* Kreverse (Node* &head, int k) {
    // if there is no node
    if (head == NULL) {
        return NULL;
    }

    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;
    int count = 0;

    while (curr!=NULL && count < k) { //so that curr doesn't go beyond the list and count<k is done so that we know the check of groups
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++; 
        // till now we have solved one given group of nodes, rest will be done by recursion
    }

    // recursive approach
    if (forward != NULL) {
        head->next = Kreverse(forward,k);
    }

    return prev;
}

int main () {
    Node* head = NULL;
    insertAtHead(head,30);
    insertAtHead(head,20);
    insertAtHead(head,10);
    print(head);

    Node* reversed = Kreverse(head,3);
    print(reversed);
}