/*📘 Problem: Longest Subarray With Sum at Most K

You are given an array of non-negative integers nums and an integer k.

Return the length of the longest contiguous subarray such that the sum of its elements is less than or equal to k.

🔹 Input

An integer array nums

An integer k

🔹 Output

Return a single integer: the maximum length of a subarray whose sum ≤ k
🔹 Example 1
Input: nums = [2, 5, 1, 7, 10], k = 14
Output: 3
Explanation: The subarray [5, 1, 7] has sum = 13 ≤ 14 and length = 3.*/
#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    int left = 0, right = 0;
    int sum = 0, maxLen = 0;

    while (right < n) {
        sum += arr[right];

        while (left <= right && sum > k) {
            sum -= arr[left];
            left++;
        }

        if (sum <= k) {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
    }

    return maxLen;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << longestSubarray(arr, k);

    return 0;
}
