#include <iostream>
#include <vector>
using namespace std;


string commonPrefix (vector<string> &str, int n) {
    string ans = "";
    for (int i=0; i<str[0].length(); i++) {
        char ch = str[0][i];
        bool match = true;
        for (int j=1; j<n; j++) {
            //if not same
            if (str[j].size() < i || ch != str[j][i]) {
                match = false;
                break;
            }
        }
        if (match == false) {
            break;
        }
        else ans.push_back(ch);
    }
    return ans;
}


int main () {
    vector<string> str;
    str.push_back("code");
    str.push_back("coding");
    str.push_back("coder");

    cout << commonPrefix(str,str.size());
}