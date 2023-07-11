#include <iostream>
using namespace std;

int reverse(int given_arr[], int given_size=0) {
    int start=0;
    int end=given_size-1;
    
    //the idea is to start from both the ends and replace each
    // element one by one until we are half way when the only
    // one element is left in case of odd number of elments and
    // and all the elements are done in case of even
    while (start<=end)
    {
        swap(given_arr[start],given_arr[end]); //this inbuilt
        // function is used to replace elements with each other
        // i.e. swap their positions
        start++;
        end--;
    }
    return 0;
}

void array_printer(int given_arr[], int given_size=0) {
    for (int i=0; i<given_size; i++) {
        cout << given_arr[i] << " ";
    }
}

int main() {
	int arr[] {2,7,1,-4,11};
    reverse(arr,5);
    array_printer(arr,5);
}

