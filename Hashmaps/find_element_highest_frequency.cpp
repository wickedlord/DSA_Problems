#include <bits/stdc++.h>
using namespace std;


int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int,int> m;
    int maxFreq = 0;
    int ans = 0;
    //storing count of each number in array
    for (int i=0; i<n; i++) {
        m[arr[i]]++;
        maxFreq = max(maxFreq, m[arr[i]]);
    }

    //traversing array from the start to find the first element with max frquency
    for (int i=0; i<n; i++) {
        if (m[arr[i]] == maxFreq) {
            ans = arr[i];
            break;
        }
    }

    return ans;
}

int main () {
    vector<int> arr = {0, -5, -2, -4, 2, -2, -3, -1, -1, -3};
    cout << maximumFrequency(arr,10);
}