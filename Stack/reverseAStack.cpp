#include <bits/stdc++.h>
using namespace std;

int main () {
    string str = "devansh";
    stack<char> s;
    for (int i = 0; i<str.size(); i++) {
        s.push(str[i]);
    }

    string ans = "";
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    cout << ans;
}