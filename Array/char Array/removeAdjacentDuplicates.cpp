#include <bits/stdc++.h>
using namespace std;

int indexer(string s) {
        int index=0;
        for (int i=0; i<s.size(); i++) {
            if (s[i]==s[i+1])
                index=i;
            if (index>0) 
                return index;
        }
        return index;
    }
    
    string removeDuplicates(string s) {
        int index = indexer(s);
        while (s[index]==s[index+1]) {
            s.erase(index,2);
            index = indexer(s);
        }
        return s;
    }