#include "NodeForSinglyLL.cpp"
#include <map>

bool cycleDetection (Node* head) {
    // this approach uses creation of a map for storing boolean values representing 
    // which node is visited and which is not.

    if (head == NULL) {
        return false;
    }

    map <Node*, bool> visited; 
    // this contains every node of the list with a corresponding true or false value for every node visited.

    Node* temp = head;
    while (temp != NULL) {
        if (visited[temp] == true) {
            // this means that a node has been visited before, hence a cycle is present.
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }

    return false;
}

Node* FloydCycle (Node* head) {
    if (head == NULL) {
        return NULL;
    }
    
    Node* slow = head;
    Node* fast = head;

    while (slow != NULL && fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
        }

        slow = slow->next;

        //fast is moved two steps and slow is moved single step. If a loop is present, they
        // will definitely meet.
        if (slow==fast) {
            return slow;
        }
    }
    return NULL;
}

Node* startingNode (Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* intersection = FloydCycle(head);
    if (intersection == NULL) {
        return NULL;
    }

    /*logic here is that if the length of the straight chain of the LL is A and the 
    length of loop before the intersection is B and after it the length is C, 
    then A+B = x*C . Hence slow will definitely meet intersection after some cycles*/
    Node* slow = head;
    while (slow != intersection) {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

Node* removeLoop (Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* start = startingNode(head);

    if (start == NULL) {
        return head;
    }

    Node* temp = start;

    while (temp->next != start) {
        temp = temp->next;
    }

    // found the element connecting back to some element in the list
    // pointing it to NULL will remove the connection.
    temp->next = NULL;
    return head;
}

int main () {
    Node* head = NULL;
    insertAtHead(head, 40);
    Node* tail = head;
    insertAtHead(head, 30);
    insertAtHead(head, 20);
    tail->next = head;
    insertAtHead(head, 10);

    //cout << cycleDetection(head);
    // cout << head->data << endl;
    //Node* intersection = FloydCycle(head);
    //cout << head << endl;
    //Node* cycleStarting = startingNode(head);
    removeLoop(head);
    print(head);
}