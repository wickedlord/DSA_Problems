// this is a codestudio problem where we have to find the
// intersection of the two arrays, i.e., find the common elements
// and return an array/vector consisting of those elements

#include<iostream>
#include<vector>
using namespace std;

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	vector<int> ans;
    int i=0, j=0;
    
    while (i<n && j<m) { 
    //we haven't used for loop due to time
    //complexity, as it will require two nested loops and also
    //it was all possible only because of the condition that the
    //given arrays are non-decreasing in nature.
        
        if (arr1[i]==arr2[j]) {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        
        else if (arr1[i]>arr2[j])
            j++;
        
        else i++;
    }
    
    return ans;
}

int main () {
    vector<int> a1 {1,2,2,2,3,4};
    vector<int> a2 {2,2,3,3};

    findArrayIntersection(a1,6,a2,4);
}