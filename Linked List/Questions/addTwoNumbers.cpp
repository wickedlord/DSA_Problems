#include "NodeForSinglyLL.cpp"

Node* reverse (Node* head) {
    Node* curr = head;
    Node* forward = NULL;
    Node* prev = NULL;
    
    while (curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    
    return prev;
}

void insertAtTail (Node* &head, Node* &tail, int val) {
    Node* temp = new Node(val);
    
    if (head == NULL) {
        head = temp;
        tail = temp;
        return;
    }
    
    else {
        tail->next = temp;
        tail = temp;
    }
}

Node* add(Node* first, Node* second) {
    int carry = 0;
    
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    
    while (first != NULL || second != NULL || carry != 0) {
        int val1 = 0;
        if (first != NULL) {
            val1 = first->data;
        }
        int val2 = 0;
        if (second != NULL) {
            val2 = second->data;
        }
        
        int sum = carry + val1 + val2;
        
        int digit = sum%10;
        
        insertAtTail(ansHead, ansTail, digit);
        
        carry = sum/10;
        
        if (first != NULL) {
            first = first->next;
        }
        
        if (second != NULL) {
            second = second->next;
        }
    }
    return ansHead;
}

//Function to add two numbers represented by linked list.
Node* addTwoLists(Node* first, Node* second)
{
    // step 1: reverse both the LL to add them
    first = reverse(first);
    second = reverse(second);
    
    // step 2: add them
    Node* ans = add(first,second);
    
    // step 3: now reverse it to get the exact answer
    ans = reverse(ans);
    
    return ans;
}

int main () {
    Node* first = NULL;
    insertAtHead(first,0);
    insertAtHead(first,9);
    insertAtHead(first,1);

    Node* second = NULL;
    insertAtHead(second,5);
    insertAtHead(second,2);

    Node* answer = addTwoLists(first,second);
    print(answer);
}