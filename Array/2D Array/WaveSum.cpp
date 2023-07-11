#include <bits/stdc++.h> 
using namespace std;

//logic is that if the column number is odd, we will have to start
//from the bottom and in case of 0 or even, start from the top.

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector <int> ans;
    for (int i=0; i<mCols; i++) {
        //checking for odd
        if ((i%2)!=0) {
            //printing from bottom to top
            for (int j=nRows-1; j>=0; j--) {
                ans.push_back(arr[j][i]);
            }
        }
        else {for (int j=0; j<nRows; j++) {
            ans.push_back(arr[j][i]);
            }
        }
    }
    return ans;
}