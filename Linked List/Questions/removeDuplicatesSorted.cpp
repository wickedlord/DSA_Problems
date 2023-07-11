#include "NodeForSinglyLL.cpp"

Node* removeDuplicates (Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* curr = head;
    while (curr != NULL) {
        // checking if the data of next node is equal to the current one
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
    removeDuplicates(head);
    print(head);
}