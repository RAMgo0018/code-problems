/*Given an integer array arr, rotate the array to the left by one position.

A left rotation by one means that each element moves to its previous index, and the first element moves to the end of the array.
arr = [1, 2, 3, 4, 5]
arr = [2, 3, 4, 5, 1]
*/
#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int>& arr) {
    int n = arr.size();
    if(n <= 1) return;
    int first = arr[0];
    for(int i = 1; i < n; i++)
        arr[i-1] = arr[i];
    arr[n-1] = first;
}

int main() {
    int n;
    cin >> n;   // size of array

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    rotate(arr);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
