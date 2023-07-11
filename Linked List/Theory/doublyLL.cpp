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

    //destructor
    ~Node () {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            this->next=NULL;
        }
        cout << "Deleted node of value " << value << endl;
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



int listlength (Node* &head) {
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
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



void insertAtTail (Node* &head, Node* &tail, int data) {
    if (tail == NULL) {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else {
        Node* temp = new Node(data);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}



void insertAtPosition (Node* &head, Node* &tail, int position, int data) {
    if (position == 1) {
        insertAtHead(head, tail, data);
        return;
    }

    else {
        Node* nodeToBeInserted = new Node(data);
        Node* temp = head;
        int count = 1;

        while (count < position-1) {
            temp = temp->next;
            count++;
        }

        if (temp->next != NULL) {
            nodeToBeInserted->next = temp->next;
            temp->next->prev = nodeToBeInserted;
            nodeToBeInserted->prev = temp;
            temp->next = nodeToBeInserted;
        }

        else {
            insertAtTail(head,tail,data);
            return;
        }
    }
}



void deleteNode (Node* &head, Node* &tail, int position) {
    // deletion of head node
    if (position == 1) {
        Node* temp = head;
        head = temp->next;
        head->prev = NULL;

        //freeing memory
        temp->next=NULL;
        delete temp;
    }

    else {
        // deletion of node in the middle or at the end
        Node* curr = head;
        Node* old = NULL;
        int cnt = 1;

        while (cnt < position) {
            old = curr;
            curr = curr->next;
            cnt++;
        }

        curr->prev = NULL;
        old->next = curr->next;
        // pointing tail to the last node
        if (curr->next == NULL) {
            tail = old;
        }
        else curr->next->prev = old->next;

        // freeing memory
        curr->next = NULL;
        delete curr;
    }
}



int main () {
    Node* node1 = new Node(20);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, tail, 10);
    print(head,tail);

    insertAtTail(head, tail, 30);
    print(head,tail);

    insertAtPosition(head, tail, 4, 15);
    print(head,tail);

    deleteNode(head,tail,4);
    print(head,tail);
}