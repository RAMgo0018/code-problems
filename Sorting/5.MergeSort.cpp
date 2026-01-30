/*Given an array, arr[]. Sort the array using Merge sort algorithm.

Examples :

Input: arr[] = [4, 1, 3, 9, 7]
Output: [1, 3, 4, 7, 9]
Explanation: After Sorting the array in ascending order of their values is [1, 3, 4, 7, 9].*/
#include <bits/stdc++.h>
using namespace std;

/*
    Function to merge two sorted subarrays
    a[lb ... mid] and a[mid+1 ... ub]
*/
void merge(int a[], int lb, int mid, int ub)
{
    int i = lb;        // starting index of left subarray
    int j = mid + 1;   // starting index of right subarray
    int k = lb;        // starting index of temporary array

    int temp[1000];    // temporary array to store sorted elements

    // Compare elements from both subarrays and store smaller one in temp[]
    while(i <= mid && j <= ub)
    {
        if(a[i] <= a[j])
        {
            temp[k] = a[i];
            i++;
        }
        else
        {
            temp[k] = a[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left subarray (if any)
    while(i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }

    // Copy remaining elements of right subarray (if any)
    while(j <= ub)
    {
        temp[k] = a[j];
        j++;
        k++;
    }

    // Copy sorted elements back to original array
    for(int p = lb; p <= ub; p++)
    {
        a[p] = temp[p];
    }
}

/*
    Recursive function to divide the array
*/
void mergeSort(int a[], int lb, int ub)
{
    if(lb < ub)
    {
        int mid = (lb + ub) / 2;

        // Sort left half
        mergeSort(a, lb, mid);

        // Sort right half
        mergeSort(a, mid + 1, ub);

        // Merge both halves
        merge(a, lb, mid, ub);
    }
}

int main()
{
    int a[] = {7, 6, 10, 5, 9, 2, 1};
    int n = sizeof(a) / sizeof(a[0]);

    mergeSort(a, 0, n - 1);

    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
