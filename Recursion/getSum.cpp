#include <iostream>
using namespace std;

int getSum (int arr[], int size) {
    //base case when the array has ended or the size of the array is equal to 0
    if (size==0) {
        return 0;
    }
    //processing
    int sum = arr[0];
    //recursive call
    sum += getSum(arr+1,size-1);
    return sum;
}

int main () {
    int arr[1] = {2};
    int size = 1;
    cout << getSum(arr,size);

}