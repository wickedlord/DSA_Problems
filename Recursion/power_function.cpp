#include<iostream>
using namespace std;

int power (int a , int b) {
    // base cases
    if (b==0) {
        return 1;
    }
    if (b==1) {
        return a;
    }
    
    int ans = power(a,b/2);
    if (b%2==0) {
        return ans*ans;
    }
    else return a*ans*ans;
}

int main () {
    int a =0;
    cin >> a;
    int b=0;
    cin >> b;
    cout << endl;

    cout << power(a,b);
}
