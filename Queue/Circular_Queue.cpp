#include <bits/stdc++.h> 
class CircularQueue{
    int *arr;
    int size;
    int front;
    int rear;
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if ((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))) {
            // case when queue is full
            return false;
        }

        else if (front == -1) { //inserting the first element
            front = rear = 0;        
        }

        else if (rear == size-1 && front != 0) { //cyclic nature
            rear = 0;
        }

        else { // normal case
            rear++;
        }

        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if (front == -1) { //to check if the queue is empty
            return -1;
        }

        int ans = arr[front]; //storing the front element
        arr[front] = -1; //deleting the element

        if (front == rear) { //only single element is there
            front = rear = -1; //resetting them
            return ans;
        }

        else if (front == size-1) { //to maintain cyclic nature
            front = 0;
        }

        else { //normal case
            front++;
        }

        return ans;
    }
};