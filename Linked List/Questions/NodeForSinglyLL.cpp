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

    //destructor
    ~Node () {
        int value = this -> data;
        if (this -> next != NULL) {
            this-> next = NULL;
            delete next;
            
        }
        cout << "Deleted node of data " << value << endl;
    }
};

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