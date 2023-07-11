#include <iostream>
using namespace std;

void say_digits (int n, string arr[]) {
    if (n==0) {
        return;
    }
    
    int digit = n%10;
    n=n/10;

    say_digits(n,arr);
    cout << arr[digit] << " ";
}

int main () {
    string arr[10] = {"zero", "one", "two", "three", "four", "five", 
                      "six", "seven", "eight", "nine"};
    
    int n = 0;
    cin >> n;

    say_digits(n,arr);
}