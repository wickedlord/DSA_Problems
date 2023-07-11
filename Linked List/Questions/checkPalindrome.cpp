#include "NodeForSinglyLL.cpp"
#include <vector>

bool checkPalindrome (vector<int> arr) {
    int n = arr.size();
    int s = 0;
    int e = n-1;
    while (s<=e) {
        if (arr[s]!=arr[e]) {
            return 0;
        }
        s++;
        e--;
    }
    return 1;
}

//Function to check whether the list is palindrome.
bool isPalindrome(Node *head)
{
    vector<int> arr;
    Node* head1 = head;
    while (head1 != NULL) {
        arr.push_back(head1->data);
        head1 = head1->next;
    }
    
    return checkPalindrome(arr);
}

Node* findMiddle (Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node* reverseLL (Node* head) {
    Node* curr = head;
    Node* forward = NULL;
    Node* prev =  NULL;
    
    while (curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

bool newApproach (Node* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    // step 1: find the middle of the linked list
    Node* middle = findMiddle(head);

    // step 2: reverse the linked list after middle
    Node* newHead = reverseLL(middle->next);

    // step 3: compare data
    Node* head1 = head;
    Node* head2 = newHead;
    while (head2 != NULL) {
        if (head1->data != head2->data) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return true;
}

int main () {
    Node* head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 1);
    insertAtHead(head, 4);
    insertAtHead(head, 4);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    insertAtHead(head, 2);
    insertAtHead(head, 5);
    insertAtHead(head, 2);
    insertAtHead(head, 4);

    //cout << "Palindrome is " << isPalindrome(head) << endl;
    cout << "Palindrome is " << newApproach(head) << endl;
}