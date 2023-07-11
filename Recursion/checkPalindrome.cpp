#include <iostream>
using namespace std;

bool palindrome (string s, int i, int j) {
    if (i>j) {
        return true;
    }

    if (s[i]!=s[j]) {
        return false;
    }

    // recursive call; do not write i++ and j++ as it will be passed &
    // then incremented
    else return palindrome(s,i+1,j-1);
}

int main () {
    string s = "acbbca";
    int i =0 ;
    int j= s.size()-1;
    if (palindrome(s,i,j)) {
        cout << "It's a palindrome!" << endl;
    }
    else cout << "It's not a palindrome!" << endl;
}