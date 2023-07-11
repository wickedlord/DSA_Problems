#include "NodeForSinglyLL.cpp"

Node* solve(Node* first, Node* second) {
    if (first->next == NULL) {
        first->next = second;
        return first;
    }

    Node* curr1 = first;
    Node* next1 = first->next;
    Node* curr2 = second;
    Node* next2 = second->next;

    while (next1 != NULL && curr2 != NULL) {
        if (curr2->data >= curr1->data && curr2->data <= next1->data) {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;

        }

        else {
            curr1 = next1;
            next1 = next1->next;

            if (next1 == NULL) {
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node* sortTwoLists(Node* first, Node* second)
{
    if (first == NULL) {
        return second;
    }
    if (second == NULL) {
        return first;
    }

    if (first->data <= second->data) {
        solve(first,second);
    }

    else solve(second,first);

}

int main () {
    Node* first = NULL;
    insertAtHead(first,5);
    insertAtHead(first,4);
    insertAtHead(first,1);

    Node* second = NULL;
    insertAtHead(second,5);
    insertAtHead(second,3);
    insertAtHead(second,2);

    sortTwoLists(first,second);
    print(first);
}
