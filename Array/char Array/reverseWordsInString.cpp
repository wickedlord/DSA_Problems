#include <bits/stdc++.h>
using namespace std;

string reversedWords (string s) {
    int k = s.size();
    string final = "";
    string temp = "";
    for (int i=k-1; i>=0; i--) {
        if ((s[i] != ' ') && (i!=0)) {
            temp.push_back(s[i]);
        }

        else {
            if (s[i]==' ') {
                // temp.push_back(s[i]);
                int j = temp.size();
                for (int i=0; i<j/2; i++) {
                    swap(temp[i],temp[j-i-1]);
                }
                for (int i=0; i<temp.size(); i++) {
                    final.push_back(temp[i]);
                }
                final.push_back(' ');
                temp.clear();
            }

            if (i==0) {
                temp.push_back(s[i]);
                int j = temp.size();
                for (int i=0; i<j/2; i++) {
                    swap(temp[i],temp[j-i-1]);
                }
                for (int i=0; i<temp.size(); i++) {
                    final.push_back(temp[i]);
                }
                final.push_back(' ');
                temp.clear();
            }
        }
    }
    return final;
}

int main () {
    string s = "the sky is blue";
    cout << reversedWords(s);
}