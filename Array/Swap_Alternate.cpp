#include <iostream>
using namespace std;

int swap_alternate(int given_arr[], int given_size=0) {
    int start=0;
    while (start<given_size-1) {
        swap(given_arr[start], given_arr[start+1]);
        start=start+2;
    }
    return 0;
}

void array_printer(int given_arr[], int given_size=0) {
    for (int i=0; i<given_size; i++) {
        cout << given_arr[i] << " ";
    }
}

int main() {
	int arr[] {2,7,1,-4,11,14};
    swap_alternate(arr,6);
    array_printer(arr,6);
}

