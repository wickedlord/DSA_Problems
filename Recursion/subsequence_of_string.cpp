#include <bits/stdc++.h>
using namespace std;

void solve (string str, int index, vector<string> &ans, string output) {
    if (index>=str.length()) {
        if (output.size()>0) {
            ans.push_back(output);
        }
        return;
    }

    //exclude wala case
    solve(str,index+1,ans,output);

    //include wala case
    char element = str[index];
    output.push_back(element);
    solve(str,index+1,ans,output);
}

void display(vector<string> ans) {
    for (int i=0; i<ans.size(); i++) {
        cout << ans[i] << endl;
    }
}

vector<string> subsequences (string str) {
    string output="";
    int index=0;
    vector<string> ans;
    solve(str, index, ans, output);
    display(ans);
    return ans;
}

int main () {
    string str = "abc";
    subsequences(str);
}