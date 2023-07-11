#include <iostream>
using namespace std;

string toLowerCase (string s) {
    for (int i=0; i< s.size(); i++) {
        //we use ascii values for this logic, i.e. if ascii value
        //is between that of A and Z which means any capital
        //letter.
        if (s[i]>='A' && s[i]<='Z') {
            s[i] = s[i] - 'A' + 'a';
            //s[i]-'A' will give the number of how much forward
            //we have to go from 'a' in ascii table. hence we'll
            //get the entire string in small letters.
        }
    }
    return s;
}

bool checkPalindrome(string s)
{
    string a = toLowerCase(s); //stored lowercase string
    string x;
    //removing all the extra characters and putting in a new string.
    for (int i=0; i<a.size(); i++) {
        if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z') || (a[i] >= '0' && a[i] <= '9')) {
            x.push_back(a[i]);
        }
    }
    int k = x.size();
    int i=0;
    //comparing elements from front and the back.
    while (i<=k/2) {
        if (x[i] == x[k-i-1]) {
            i++;
        }
        else return 0;
    }
    return 1;
}

int main () {
    string s = " ";
    cout << checkPalindrome(s);
}