#include <bits/stdc++.h>
using namespace std;

//function for comparing all the elements of a array in this ques.
bool arrCompare(int arr1[26], int arr2[26]) {
    for (int i=0; i<26; i++) {
        if (arr1[i]!=arr2[i]) {
            return 0;
        }
    }
    return 1;
} 

bool permutation (string s1, string s2) {

//created an array with info of count of each char in  the
//string s1
    int char1[26] = {0};
    for (int i=0; i< s1.length(); i++) {
        int index = s1[i] - 'a';
        char1[index]++;
    }

//created a new arr with info about the count of chars in s2
//which goes in groups of size of s1.
    int i = 0;
    int windowSize = s1.length();
    int char2[26] = {0};
    while (i<windowSize && i<s2.length()) {
        int index = s2[i]-'a';
        char2[index]++;
        i++;
    }

    if (arrCompare(char1,char2))
        return 1;

//travelling further in s2 after removing the the first element.
    while (i<s2.length()) {
        char newChar = s2[i];
        int index = newChar-'a';
        char2[index]++;

        char oldChar = s2[i-windowSize];
        index = oldChar-'a';
        char2[index]--;

        i++;

        if (arrCompare(char1,char2))
        return 1;
    }
    return 0;
}

int main () {
    string s1 = "ab";
    string s2 = "dcbaooo";
    cout << permutation(s1,s2);
}