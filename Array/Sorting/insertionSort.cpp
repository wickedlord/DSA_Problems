#include<bits/stdc++.h>
using namespace std;

void insertionSort(int n, vector<int> &arr){
    for (int i=1; i<n; i++) {
        //assume first element of the array to be sorted and
        //then start the loop from the second elemet
        int temp=arr[i];
        int j=i-1;
        //j is declared outside so as to use it outside the for
        //loop that we need
        for (; j>=0; j--) {
            if (arr[j]>temp)
            //comparing it with the elements before it in the
            //array
                arr[j+1]=arr[j];
                //pushing the array forward
            else 
                break;
        }
        arr[j+1]=temp;
        //so that the element do not repeat
    }
}