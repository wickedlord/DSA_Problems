#include <iostream>
using namespace std;



class Node {
    public:
    int data;
    Node* next;

    //constructor
    Node (int data) {
        this -> data = data;
        next = NULL;
    }

    
    // how a node destructor works internally:

    ~Node () {
        int value = this -> data;
        if (this -> next != NULL) {
            this-> next = NULL;
            delete next;
            
        }
        cout << "Deleted node of data " << value << endl;
    }
};




void insertAtHead (Node* &head, int d) {
    //first check if the list is empty or not by checking if the head is NULL or not.
    Node* temp = new Node(d); // a node is created for the given data
    temp -> next = head; // the pointer of temp is pointed to the head node.
    head = temp; // head is now pointing to temp, so the new head is the node temp
}




void insertAtTail (Node* &tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}



void insertAtPosition (Node* &head, Node* &tail, int position, int data) {
    // if inserting at the start
    if (position==1) {
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    //this will help in reaching the node where the new node has to be inserted
    while (cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    // solving the problem for inserting at the end
    if (temp->next==NULL) {
        insertAtTail(tail,data);
        return;
    }

    // to be inserted anywhere in the middle
    Node* nodeToBeInserted = new Node(data);
    nodeToBeInserted->next = temp->next;
    temp->next = nodeToBeInserted;
}



void deleteNode (Node* &head, Node* &tail, int position) {
    // deletion of head node
    if (position == 1) {
        Node* temp = head;
        head = head->next;

        //freeing memory
        temp->next=NULL;
        delete temp;
    }

    else {
        // deletion of node in the middle or at the end
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;

        while (cnt < position) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        // since at position = 1, the above loop wouldn't have been executed, we would
        // be equating Null to something which is not possible.

        // pointing tail to the last node
        if (curr->next==NULL) {
            tail = prev;
        }

        
        prev->next = curr->next;

        // freeing memory
        curr->next = NULL;
        delete curr;
    }
}



void print (Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}




int main () {
    Node* node1 = new Node (10);
    // cout << node1->data << endl;
    // cout << node1->next << endl;

    Node* head = node1;
    Node* tail = node1;
    print(head);

    insertAtHead (head, 20);
    print(head);

    insertAtTail(tail, 30);
    print(head);

    insertAtPosition(head, tail, 2, 15);
    print(head);

    cout << "Value of head is " << head->data << endl;
    cout << "Value of tail is " << tail->data << endl;

    deleteNode(head,tail,4);
    print(head);

    cout << "Value of head is " << head->data << endl;
    cout << "Value of tail is " << tail->data << endl;
}