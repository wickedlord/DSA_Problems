#include<bits/stdc++.h>
using namespace std;

int main () {
    int row=0;
    cin >> row;

    int col=0;
    cin >> col;

    int** arr = new int*[row];
    //we have to create an array of arrays
    for (int i=0; i<row; i++) {
        arr[i]=new int[col];
    }

    //taking inputs
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            cin >> arr[i][j];
        }
    }

    //showing output
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}