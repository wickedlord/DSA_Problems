#include <iostream>
using namespace std;

bool isPresent (int arr[][3], int key, int row, int column) {
    for (int i=0; i<row; i++) {
        for (int j=0; j<column; j++) {
            if (arr[i][j]==key)
            return 1;
        }
    }
    return 0;
}

int main () {
    int arr [3][3];
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cin >> arr[i][j];
        }
    }

    if (isPresent(arr,4,3,3))
    cout << "Present";
    else cout << "Not present";
}