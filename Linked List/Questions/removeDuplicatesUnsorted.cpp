#include "NodeForSinglyLL.cpp"
#include <map>

Node* removeDuplicates (Node* head) {
    if (head == NULL) {
        return NULL;
    }

    map<int,bool> visited;
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL) {
        // case when a same element is found in the linked list and it is not at the end.
        if (visited[curr->data] == true && curr->next != NULL) {
            Node* nodeToBeDeleted = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete(nodeToBeDeleted);
        }

        // when the same element is at the end of the list
        else if (curr->next == NULL && visited[curr->data] == true) {
            curr = NULL;
            delete(curr);
            prev->next = NULL;
        }

        // if the element is found for the first time in the list
        else {
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

int main () {
    Node* head = NULL;
    insertAtHead(head,2);
    insertAtHead(head,4);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,2);
    print(head);
    removeDuplicates(head);
    print(head);
}