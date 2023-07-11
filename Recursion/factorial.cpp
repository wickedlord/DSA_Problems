#include <bits/stdc++.h>
using namespace std;

int factorial (int n) {
    if (n==0) 
        return 1;
    //above is called base case.
    //below is the recurrence relation.
    else return n*factorial(n-1);
}

int main () {
    int n=0;
    cin >> n;

    cout << factorial (n);
}