#include "NodeForCircularLL.cpp"

bool isCircular (Node* head) {
    if (head==NULL) {
        return true;
    }

    Node* temp = head->next;

    while (temp!=NULL && temp!=head) {
        temp = temp->next;
    }

    if (temp==head) {
        return true;
    }
    else return false;
}

int main () {
    Node* tail = NULL;
    insertNode(tail,10,0);
    insertNode(tail,20,10);
    insertNode(tail,30,20);
    print(tail);

    cout << isCircular(tail);
}