#include <bits/stdc++.h>
using namespace std;

int& func (int& a) {
    int x = a;
    int& b = x;
    return b;
}
/*this type of func can be created but it wouldn't make sense as
a local copy is created on the stack during compile time and it will
get deleted as soon as the func call is terminated*/

int main () {
    /*a reference variable is used for pass by reference in a function
    kind of similar to the use of pointers, i.e., we don't want to
    create a copy of the variable.*/

    int x = 5;
    int& a = x; //to initialize a ref var
    //cout << a;

    cout << func(a);
}