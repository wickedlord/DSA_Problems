#include <iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int key)
{
    // base case; similar to the for loop one
    if (start>end)
    {
        return -1;
    }

    //processing part
    int mid = start + (end - start) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }

    //for the recursive calls
    if (arr[mid] < key)
    {
        start = mid + 1;
        return binarySearch(arr, start, end, key);
    }
    else
    {
        end = mid - 1;
        return binarySearch(arr, start, end, key);
    }
}

int main()
{
    int arr[11] = {2, 4, 6, 10, 14,18,22,38,49,55,222};
    cout << binarySearch(arr, 0, 10, 222);
}