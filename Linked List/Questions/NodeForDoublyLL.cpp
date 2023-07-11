#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    //constructor
    Node (int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(Node* head, Node* tail) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "The value of head is " << head->data << endl;
    cout << "The value of tail is " << tail->data << endl;
}

void insertAtHead (Node* &head, Node* &tail, int data) {
    //checking if the list is empty
    if (head == NULL) {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    //for non empty case
    else {
        Node* temp = new Node(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}