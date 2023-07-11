#include<iostream>
using namespace std;

char maximum (string s) {
    //converting to lowercase
    for (int i=0; i< s.size(); i++) {
        if (s[i]>='A' && s[i]<='Z') {
            s[i] = s[i] - 'A' + 'a';
        }
    }
    //assigning values to different indices corresponding to each
    //alphabet
    int maximum [26] = {0};
    for (int i=0; i<s.size(); i++) {
        int x = s[i]-'a';
        maximum[x]++;
    }

    //finding the maximum value among all the indices
    int max_element=0;
    int index=0;
    for (int i=0; i<26; i++) {
        if (maximum[i] > max_element) {
            max_element = maximum[i];
            index=i;
        }
    }
    
    //returning the character from that index
    char x = 'a' + index;
    return x;
}

int main () {
    string s = "helllo";
    cout << maximum(s);
}