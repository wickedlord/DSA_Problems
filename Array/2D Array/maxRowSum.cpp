#include<iostream>
using namespace std;

int maxSum (int arr[][3], int row, int col) {
    int maxi = INT_MIN;
    int maxRow = 0;
    for (int i=0; i<row; i++) {
        int sum = 0;
        for (int j=0; j<col; j++) {
            sum+=arr[i][j];
        }
        if (sum>maxi) {
        maxi = sum;
        maxRow = i;
        }
    }
    return maxRow;
}

int main () {
    int arr [3][3];
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cin >> arr[i][j];
        }
    }

    int maximum = maxSum(arr,3,3);
    cout << "The maximum sum is of row at index : " << maximum;
}