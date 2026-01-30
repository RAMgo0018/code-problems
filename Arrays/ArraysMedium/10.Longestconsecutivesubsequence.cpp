/*Given an array arr[] of non-negative integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

Examples:

Input: arr[] = [2, 6, 1, 9, 4, 5, 3]
Output: 6
Explanation: The consecutive numbers here are 1, 2, 3, 4, 5, 6. These 6 numbers form the longest consecutive subsquence.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        unordered_set<int> st;
        for (int x : arr) st.insert(x);

        int longest = 1;

        for (auto it : st) {
            // start of sequence
            if (st.find(it - 1) == st.end()) {
                int count = 1;
                int curr = it;

                while (st.find(curr + 1) != st.end()) {
                    curr++;
                    count++;
                }

                longest = max(longest, count);
            }
        }
        return longest;
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
    cout << obj.longestConsecutive(arr);

    return 0;
}
