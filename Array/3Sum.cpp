#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	vector<vector<int>> triplets;
    sort(arr.begin(), arr.end());
    int i=0;
    int start=i+1, end=n-1;
    for (int i=0; i<n-2; i++) {
        for (int start=i+1; start<end; i++) {
            if (arr[i]+arr[start]+arr[end]==K) {
                vector<int> temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[start]);
                temp.push_back(arr[end]);
            }

            else if (arr[i]+arr[start]+arr[end] < K) {
                start++;
            }

            else end++;
        }
    }
    return triplets;
}

int vectorPrinter (vector<vector<int>> ar, int size) {
    for (int i=0; i<ar.size(); i++) {
        for (int j=0; j<ar[j].size(); j++) {
            cout << j << " ";
        }
    }
}

int main()
{
    vector <int> arr1 {1,2,3,1,2,3};
    cout << vectorPrinter(findTriplets(arr1,6,6), findTriplets(arr1,6,6).size());
}