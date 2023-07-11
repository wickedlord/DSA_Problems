#include <iostream>
using namespace std;

class heap {
    public:
        int arr[100];
        int size;

        heap() {
            arr[0] = -1;
            size = 0;
        }

        void insert(int data) {
            size = size+1;
            int index = size;
            arr[index] = data;

            while (index > 1) {
                int parent = index/2;
                if (arr[index] > arr[parent]) {
                    swap(arr[parent],arr[index]);
                    index = parent;
                }
                else return;
            }
        }

        void deleteFromHeap () {
            if (size == 1) {
                cout << "Nothing to delete." << endl;
                return;
            }

            //step1 : swap last element with first
            arr[1] = arr[size];

            //step2: delete last element
            size--;

            //step3: put the element at its right position
            int i = 1;
            while (i < size) {
                int leftchild = 2*i;
                int rightchild = 2*i+1;
                
                if (leftchild < size && arr[leftchild] > arr[i]) {
                    swap(arr[leftchild],arr[i]);
                    i = leftchild;
                }

                else if (rightchild < size && arr[rightchild] > arr[i]) {
                    swap(arr[rightchild],arr[i]);
                    i = rightchild;
                }

                else return;
            }
        }

        void print () {
            for (int i=1; i<=size; i++) {
                cout << arr[i] << " ";
            }
        }

};


void heapify(int arr[], int n, int i) {
    int largest = i;
    int leftchild = 2*i;
    int rightchild = 2*i+1; 

    if (leftchild <= n && arr[largest] < arr[leftchild]) {
        largest = leftchild;
    }

    if (rightchild <= n && arr[largest] < arr[rightchild]) {
        largest = rightchild;
    }

    if (largest != i) {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}


int main () {
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deleteFromHeap();
    cout << endl;
    cout << "Deleting the node." << endl;
    h.print();
    cout << endl;
    cout << "Heapifying new array :" << endl;
    int arr[7] = {-1,3,2,1,5,6,4};
    int n = 7;
    for (int i=n/2; i>0; i--) {
        // n/2  ke baad sirf leaf nodes hongi, jo individually heap hoti hai
        heapify(arr,n,i);
    }
    
    for (int i=1; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}