#include <iostream>
using namespace std;

void reverse (int i, string s) {
    //base case
    if (i>(s.size())-i-1) {
        cout << s << endl;
        return;
    }

    //processing
    swap (s[i],s[((s.size())-i-1)]);
    i++;

    //rr
    reverse(i,s);

}

int main () {
    string s = "hello";
    int i = 0;
    reverse(i,s);

    //another way could be to pass by reference and then printing out
    //the updated array in the main function
    //void reverse (int i, int j, string& s)
}