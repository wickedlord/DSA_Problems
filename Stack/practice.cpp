#include <bits/stdc++.h>

using namespace std;
vector<string> generateBinaryNumbers(int n)
{
    vector<string> ans;
    for (int i=1; i<=n; i++) {
        stack<int> s;
        int number = i;
        while (number!=0) {
            number = number/2;
            if (number==0) {
                s.push(0);
            }
            else {
                s.push(1);
            }
        }
        

        cout << "Printing stack " << endl;
        while(!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << "done printing" << endl;


        int num = 0;
        int count = 0;
        while (!s.empty()) {
            int x = s.top();
            num = num + x*(10^count);
            cout << num << " ";
            s.pop();
            count++;
        }
        cout << "done first" << endl;
        string ans_string = to_string(num);
        ans.push_back(ans_string);
    }

    return ans;
}

// void print (vector<string> input) {
//     for (int i=0; i<input.size(); i++) {
//         cout << input[i] << " ";
//     }
// }

int main () {
    int n = 6;
    vector<string> output = generateBinaryNumbers(n);
    print(output);
}