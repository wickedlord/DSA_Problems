#include <bits/stdc++.h> 
class Deque
{
    int *arr;
    int size;
    int front;
    int rear;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        size = n;
        front = rear = -1;
        arr = new int[size];
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        if (isFull()) {
            return false;
        }

        else if (isEmpty()) {
            front = rear = 0;
        }

        else if (front == 0 && rear != size-1) {
            front = size-1;
        }

        else front--;

        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if (isFull()) {
            // case when queue is full
            return false;
        }

        else if (isEmpty()) { //inserting the first element
            front = rear = 0;        
        }

        else if (rear == size-1 && front != 0) { //cyclic nature
            rear = 0;
        }

        else { // normal case
            rear++;
        }

        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if (isEmpty()) { //to check if the queue is empty
            return -1;
        }

        int ans = arr[front]; //storing the front element
        arr[front] = -1; //deleting the element

        if (front == rear) { //only single element is there
            front = rear = -1; //resetting them
        }

        else if (front == size-1) { //to maintain cyclic nature
            front = 0;
        }

        else { //normal case
            front++;
        }

        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if (isEmpty()) { //to check if the queue is empty
            return -1;
        }

        int ans = arr[rear]; //storing the front element
        arr[rear] = -1; //deleting the element

        if (front == rear) { //only single element is there
            front = rear = -1; //resetting them
            return ans;
        }

        else if (rear == 0) { //to maintain cyclic nature
            rear = size-1;
        }

        else { //normal case
            rear--;
        }

        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if (isEmpty()) {
            return -1;
        }

        else return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if (isEmpty()) {
            return -1; 
        }

        else return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if (front == -1) {
            return true;
        }

        else return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if ((front == 0 && rear == size-1) || (front != 0 /*to handle if front = 0*/ && rear == (front-1)%(size-1))) {
            return true;
        }

        else return false;
    }
};