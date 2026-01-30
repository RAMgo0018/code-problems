/*Given an array, arr[]. Sort the array using Quick sort algorithm.

Examples :

Input: arr[] = [4, 1, 3, 9, 7]
Output: [1, 3, 4, 7, 9]
Explanation: After Sorting the array in ascending order of their values is [1, 3, 4, 7, 9].*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        if(low < high)
        {
            int loc = partition(arr, low, high);
            quickSort(arr, low, loc - 1);
            quickSort(arr, loc + 1, high);
        }
    }

    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[low];
        int start = low;
        int end = high;

        while(start < end)
        {
            while(arr[start] <= pivot && start < high)
            {
                start++;
            }

            while(arr[end] > pivot)
            {
                end--;
            }

            if(start < end)
            {
                swap(arr[start], arr[end]);
            }
        }

        swap(arr[low], arr[end]);
        return end;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    obj.quickSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
