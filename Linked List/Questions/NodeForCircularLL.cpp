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
        int value = this->data;
        if (this->next!=NULL) {
            delete next;
            next = NULL;
        }
        cout << "Deleted node with value " << value << endl;
    }
};



void insertNode (Node* &tail, int data, int element) {

    Node* temp = new Node(data);
    //if the list is empty
    if (tail==NULL) {
        tail = temp;
        temp->next = temp;
    }

    //for other cases considering element is always present
    //since there is no head or logically tail; there is same code for insertion at head, tail or middle
    else {
        Node* curr = tail;

        while (curr->data != element) {
            curr = curr->next;
        }

        temp->next = curr->next;
        curr->next = temp;
    }
}



void print (Node* tail) {
    if (tail==NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = tail;
    do {
        cout << tail->data << " " ;
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}



void deleteNode (Node* &tail, int element) {
    //empty list case
    if (tail==NULL) {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }

    else {
        Node* prev = tail;
        Node* curr = prev->next;

        while (curr->data != element) {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        //case of only single node
        if (prev == curr) {
            tail = NULL;
        }

        //case of >=2 nodes
        if (tail==curr) {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}