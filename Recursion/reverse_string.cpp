#include <iostream>
using namespace std;

void reverse (int i, int j, string s) {
    //base case
    if (i>j) {
        cout << s << endl;
        return;
    }

    //processing
    swap (s[i],s[j]);
    i++;
    j--;

    //rr
    reverse(i,j,s);

}

int main () {
    string s = "hello";
    int i = 0;
    int j = s.size()-1;
    reverse(i,j,s);

    //another way could be to pass by reference and then printing out
    //the updated array in the main function
    //void reverse (int i, int j, string& s)
}