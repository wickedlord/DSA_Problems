#include <iostream>
using namespace std;

int nth_stairs(long long n) {
    //no way to reach -1 step
    if (n<0) {
        return 0;
    }
    //when on 0, you can reach above by only one way to 1
    if (n==0) {
        return 1;
    }

    //RR
    else return nth_stairs(n-1) + nth_stairs(n-2);
}

int main () {
    long long n = 0;
    cin >> n;

    cout << nth_stairs(n);
}