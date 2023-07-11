#include<iostream>
using namespace std;

void rowSum (int arr [][3], int row, int col) {
    for (int i=0; i<row; i++) {
        int sum = 0;
        for (int j=0; j<col; j++) {
            sum += arr[i][j];
        }
        cout << "Sum of row " << i << " is : " << sum << endl;
    }
}

void colSum (int arr [][3], int row, int col) {
    for (int i=0; i<row; i++) {
        int sum = 0;
        for (int j=0; j<col; j++) {
            sum += arr[j][i];
        }
        cout << "Sum of col " << i << " is : " << sum << endl;
    }
}

int main () {
    int arr [3][3];
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cin >> arr[i][j];
        }
    }

    rowSum(arr,3,3);
    colSum(arr,3,3);
}