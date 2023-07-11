#include <bits/stdc++.h>
using namespace std;

class KQueue {
    public:
        int *front;
        int *rear;
        int *next;
        int *arr;
        int freeSpot;

        KQueue (int n, int k) {
            front = new int[k];
            rear = new int[k];
            arr = new int[n];
            next = new int[n];
            freeSpot = 0;

            for (int i=0; i<k; i++) {
                front[i] = -1;
                rear[i] = -1;
            }

            for (int i=0; i<n; i++) {
                next[i] = i+1;
            }
            next[n-1] = -1;
        }

        void enqueue (int data, int qn) {
            //check overflow condition
            if (freeSpot == -1) {
                cout << "No space available." << endl;
                return;
            }

            int index = freeSpot;
            freeSpot = next[index];

            //check for first element
            if (front[qn-1] == -1) {
                front[qn-1] = index;
            }

            else {  // link further elements with previous one
                next[rear[qn-1]] = index;
            }

            // marking that no space is available for that index
            next[index] = -1;

            // updating the rear of that queue
            rear[qn-1] = index;

            // filling the data in the array
            arr[index] = data;
        }

        void dequeue (int qn) {
            // check for underflow condiiton
            if (front[qn-1] == -1) {
                cout << "No element present." << endl;
            }

            //find the index of queue to be popped
            int index = front[qn-1];

            // move front ahead so that the element is popped
            front[qn-1] = next[index];

            //utitlizing the now avaailable free space
            next[index] = freeSpot; // to move after the available block
            freeSpot = index; //it's the available block
        }
};

int main () {
    KQueue q(9,3);
    q.enqueue(11,1);
    q.enqueue(12,2);
    q.enqueue(13,3);
    q.enqueue(14,1);
    q.enqueue(15,2);
    q.enqueue(16,3);
    q.enqueue(17,1);
    q.enqueue(18,2);
    q.enqueue(19,3);

}