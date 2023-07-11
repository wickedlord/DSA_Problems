#include<iostream>
using namespace std;

int fibonacci (int n) {
    //base conditions
    if (n==1) {
        return 0;
    }

    if (n==2) {
        return 1;
    }

    //recursive relation
    else return fibonacci(n-1) + fibonacci(n-2);
}

int main () {
    int n=0;
    cin >> n;

    cout << fibonacci(n) << endl;

    //using for loop
    int arr[1000] = {0};
    arr[0]=0;
    arr[1]=1;
    for (int i=2; i<n; i++) {
        arr[i]=arr[i-1]+arr[i-2];
    }

    int ans = arr[n-2] + arr[n-3];
    cout << ans;
}