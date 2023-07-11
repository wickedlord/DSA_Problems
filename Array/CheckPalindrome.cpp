#include<iostream>
using namespace std;

bool helper(char input[],int start,int end) {
    if (input[start]!=input[end]) {
        return false;
    }
    if (start==end || start>end) {
        return true;
    }
    else helper(input, start+1, end-1);    
}
  

bool checkPalindrome(char input[]) 
{ 
    static int end=-1;
    static int start=0;  
    for(int i=0;i<50;i++){
        if(input[i]=='\0')
            break;
        else
            end++;
    }
    //cout << start << " " << end;
    return helper(input,start,end);
    //if(helper)
    //return true;
    //else 
    //return false;
}


int main() {
    char input[50];
    cin >> input;
    //for (int i=0; i<50; i++) {
    //    cout << input[i] << endl;
    //}
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}