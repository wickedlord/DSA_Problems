#include <iostream>
using namespace std;

bool linearSearch (int arr[], int size, int key) {
    if (size==0) {
        return false;
    }

    if (arr[0]==key) {
        return true;
    }

    else {
        bool found;
        return found = linearSearch(arr+1, size-1, key);
    }
}

int main () {
    int arr[5] = {2,4,6,8,10};
    int size = 5;
    if (linearSearch(arr,size,7))
        cout << "Key is present" << endl;
    else cout << "Key not found" << endl;
}