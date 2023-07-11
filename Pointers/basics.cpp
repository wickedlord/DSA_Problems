#include <bits/stdc++.h>
using namespace std;

int main () {
    int num = 6;
    int *ptr= &num; //& is address of operator
    cout << *ptr << endl; // this is dereferencing a pointer
    cout << ptr << endl; //this shows the address of the num
    cout << sizeof(num) << endl; //shows size of integer
    cout << sizeof(ptr) << endl; // shows sizxe of pointer

}