#include <bits/stdc++.h>
using namespace std;

int sum (int arr[], int size) {
    int s = 0;
    for (int i =0; i<size; i++) {
        s += arr[i];
    }
    return s;
}

int main () {
    /*a 'new' keyword is used to dynamically allocate memory from the
    heap and it always returns a pointer*/
    int* a = new int;
    *a = 5;
    cout << *a << endl;

    //initialize a dynamic array
    int n = 0;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i<n ; i++) {
        cin >> arr[i];
    }

    cout << sum(arr, n);
}