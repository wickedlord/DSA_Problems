#include<bits/stdc++.h>
using namespace std;

int main () {
    int row=0;
    cin >> row;

    int** arr = new int*[row];
    //we have to create an array of arrays
    for (int i=0; i<row; i++) {
        int col=0;
        cout << "Enter no. of cols in row " << i << " : " << endl;
        cin >> col;
        arr[i]=new int[col];
    }
}