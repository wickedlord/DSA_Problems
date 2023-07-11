#include <iostream>
#include <string>
#include <vector>
using namespace std;
void sort012(int *arr, int n)
{
    int zeros = 0;
    int ones = 0;
    int twos = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            zeros++;
        }
        else if (arr[i] == 1)
        {
            ones++;
        }
        else {
            twos++;
        }
    }
    cout << zeros << endl;
    cout << ones << endl;
    cout << twos << endl;
    for (int i = 0; i < n; i++)
    {
        if (zeros > 0)
        {
            arr[i] = 0;
            zeros--;
        }
        else if (ones > 0)
        {
            arr[i] = 1;
        }
        else if (twos > 0)
        {
            arr[i] = 2;
            twos--;
        }
    }
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[6] = {0, 1, 2, 2, 1, 0};
    int n = 6;
    sort012(arr,n);
}
