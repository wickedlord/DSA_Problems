#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key)
{
    int start = 0, end = size - 1;
    int mid = (start + end) / 2;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }

        if (arr[mid] < key)
        {
            start = mid + 1;
        }

        else
        {
            end = mid - 1;
        }

        mid = (start + end) / 2;
    }
    return -1;
}

int main()
{
    int arr1[8]{1, 2, 3, 4, 5, 6, 7, 8};
    cout << binarySearch(arr1, 8, 5);
}