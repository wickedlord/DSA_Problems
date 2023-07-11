#include "NodeForSinglyLL.cpp"

Node * uniqueSortedList(Node * head) {
    if (head == NULL) {
        return NULL;
    }

    Node* curr = head;
    while (curr != NULL) {
        if ((curr->next != NULL) && (curr->next->data == curr->data)) {
            Node* forward = curr->next->next; 
            Node* nodeToDelete = curr->next;
            delete(nodeToDelete);
            curr->next = forward; 
        }
        else {
            curr = curr->next;
        }
    }
    return head;
}

int main () {
    Node* head = NULL;
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,2);
    insertAtHead(head,1);
    print(head);
    uniqueSortedList(head);
    print(head);
}