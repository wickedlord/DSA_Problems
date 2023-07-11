#include <iostream>
using namespace std;

//we are going to create a function for merging two array and
//putting the values of those array in a new one
//p.s. the question on leetcode is for merging them together
//in the first given array which is already the size of the
//sum of sizes of both the arrays
//to solve that, just empty the 1st vector using .clear method
//and then use a for loop to push back the elements already
//present in the new vector created while comparing

void merge (int arr1[], int n, int arr2[], int m)
{
    int i = 0; //for arr1
    int j = 0; //for arr2
    int mergedArr[6] = {0}; //array to be finally returned
    
    //remember to initialize the array to 0 as it might return
    //garbage values in it
    
    int k=0; //for mergedArr
    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            mergedArr[k]=arr1[i];
            i++;
            k++;
        }
        else
        {
            mergedArr[k]=arr2[j];
            j++;
            k++;
        }
    }
    //till here we have merged the array till the size of the
    //array whichever is actually smaller

    while (j < n)
    {
        mergedArr[k]=arr2[j];
        j++;
        k++;
    }

    // only one of these while loop will be executed and the
    //the one which will be executed will used to add the
    //remaining elements of the larger array.
    
    while (i < m)
    {
        mergedArr[k]=arr1[i];
        i++;
        k++;
    }

    for (int x=0; x<6; x++) {
        cout << mergedArr[x] << " ";
    }
    
    //printing the final array to confirm whatever we have done.
}

int main () {
    int arr1[3] = {1,2,3};
    int arr2[3] = {4,5,6};
    merge(arr1, 3, arr2, 3);
}