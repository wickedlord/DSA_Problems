#include <bits/stdc++.h> 
class Queue {
    int *arr;
    int size;
    int qfront;
    int rear;
public:
    Queue() {
        // Implement the Constructor
        size = 10000; //since size is not given in the constructor
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if (qfront == rear) {
            return true;
        }
        else return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if (rear == size) {
            return;
        }

        else {
            arr[rear] = data;
            rear++;
            return;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if (qfront == rear) {
            return -1;
        }

        else {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if (qfront == rear) { //so that the initial space is not wasted
                qfront = 0;
                rear = 0;
            }

            return ans;
        }
    }

    int front() {
        // Implement the front() function
        if (qfront == rear) {
            return -1;
        }

        else return arr[qfront];
    }
};