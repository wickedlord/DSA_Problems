#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    //constructor
    Node (int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* reverseLLiterative(Node* &head) {
    //when there are 0 nodes or only 1 node is there
    if (head == NULL || head->next == NULL) {
        return head;
    }

    //for more than 1 node
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while (curr!=NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

void revereseRecursively (Node* &head, Node* prev, Node* curr) {
    if (curr==NULL) {
        head = prev;
        return;
    }

    Node* forward = curr->next;
    curr->next = prev;
    revereseRecursively(head, curr, forward);
}

Node* reverseAnotherApproach (Node* head) {
    if (head==NULL || head->next == NULL) {
        return head;
    }

    Node* chhotaHead = reverseAnotherApproach(head->next);

    head->next->next = head;
    head->next = NULL;

    return chhotaHead;
}

void print (Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertAtHead (Node* &head, int data) {
    //checking if the list is empty
    if (head == NULL) {
        Node* temp = new Node(data);
        head = temp;
    }
    //for non empty case
    else {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
}


int main () {
    Node* head = NULL;
    insertAtHead(head,30);
    insertAtHead(head,20);
    insertAtHead(head,10);
    print(head);

    // Node* newNode = reverseLLiterative(head);
    // print(newNode);

    // Node* prev = NULL;
    // Node* curr = head;
    // revereseRecursively(head, prev, curr);
    // cout << "reversed LL is ";
    // print(head);

    Node* newHead = reverseAnotherApproach(head);
    print(newHead);
}