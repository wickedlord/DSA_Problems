# include "NodeForSinglyLL.cpp"

Node* sortList(Node *head)
{
    int ZeroCount = 0;
    int OneCount = 0;
    int TwoCount = 0;

    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == 0) {
            ZeroCount++;
        }
        else if (temp->data == 1) {
            OneCount++;
        }
        else if (temp->data == 2) {
            TwoCount++;
        }
        temp = temp->next;
    }

    temp = head;

    while (temp != NULL) {
        if (ZeroCount != 0) {
            temp->data = 0;
            ZeroCount--;
        }
        else if (OneCount != 0) {
            temp->data = 1;
            OneCount--;
        }
        else if (TwoCount != 0) {
            temp->data = 2;
            TwoCount--;
        }
        temp = temp->next;
    }

    return head;
}

void insertAtTail(Node* &tail, Node* curr) {
    tail->next = curr;
    tail = curr;
}


Node* sortListExtraSpace(Node *head)
{

    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    while (curr != NULL) {
        if (curr->data == 0) {
            insertAtTail(zeroTail, curr);
        }
        else if (curr->data ==1) {
            insertAtTail(oneTail, curr);
        }
        else if (curr->data ==2) {
            insertAtTail(twoTail, curr);
        }

        curr = curr->next;
    }

    // merging of all the three linked lists
    if (oneHead->next == NULL) {
        zeroTail->next = twoHead->next;
    }

    else {
        zeroTail->next = oneHead->next;
        oneTail->next = twoHead->next;
    }

    twoTail->next = NULL;
    head = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return head;
}


int main () {
    Node* head = NULL;
    insertAtHead(head,1);
    insertAtHead(head,0);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,2);
    print(head);
    // sortList(head);
    // print(head);
    Node* newHead = sortListExtraSpace(head);
    print(newHead);
}