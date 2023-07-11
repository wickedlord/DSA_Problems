#include "bits/stdc++.h"
using namespace std;
void bubblesort(int arr[], int n)
{
    int counter = 1;
    while (counter < n)
    {
        for (int i = 0; i < n - counter; i++)
        {
            if (arr[i] < arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        counter++;
    }
}
void selectionsort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
void merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1];
    int b[n2];
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        arr[k] = a[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        j++;
        k++;
    }
}
void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}
void insertionsort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int j = i - 1;
        while (arr[j] > curr && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curr;
    }
}
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, r);
}
void quicksort(int arr[], int l, int r)
{
    if (l < r)
    {
        int p1 = partition(arr, l, r);
        quicksort(arr, l, p1 - 1);
        quicksort(arr, p1 + 1, r);
    }
}
void heapify(vector<int> &a, int n, int i)
{
    int maxidx = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[maxidx])
    {
        maxidx = l;
    }
    if (r < n && a[r] > a[maxidx])
    {
        maxidx = r;
    }
    if (maxidx != i)
    {
        swap(a[i], a[maxidx]);
        heapify(a, n, maxidx);
    }
}
void heapsort(vector<int> &a)
{
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> vt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vt[i];
    }
    bubblesort(arr, n);
    selectionsort(arr, n);
    mergesort(arr, *vt.begin(),*vt.end());
    insertionsort(arr, n);
    quicksort(arr, *vt.begin(),*vt.end());
    heapsort(vt);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    for (int i = 0; i < n; i++)
    {
        cout << vt[i] << " ";
    }
    return 0;
}