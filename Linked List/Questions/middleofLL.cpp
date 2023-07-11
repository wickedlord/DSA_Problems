#include <iostream>
#include "NodeForSinglyLL.cpp"
using namespace std;

int lengthoflist (Node* head) {
    int count = 0;
    while (head!=NULL) {
        count++;
        head=head->next;
    }
    return count;
}

Node *findMiddlebasic(Node *head) {
    int iter = 1;
    int length = lengthoflist(head)/2 +1;
    while (iter < length) {
        head = head->next;
        iter++;
    }
    return head;
}

Node* betterApproach (Node* head) {
    if (head==NULL) {
        return head;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast!=NULL) {
        fast=fast->next;
        if (fast!=NULL) {
            fast=fast->next;
        }
        slow=slow->next;
    }
    return slow;
}

int main () {
    Node* head = NULL;
    insertAtHead(head,40);
    insertAtHead(head,30);
    insertAtHead(head,20);
    insertAtHead(head,10);
    print(head);

    // Node* middle = findMiddlebasic(head);
    // cout << middle->data << endl;

    Node* middle = betterApproach(head);
    cout << middle->data;
}