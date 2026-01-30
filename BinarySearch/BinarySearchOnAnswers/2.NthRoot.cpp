/*Given two integers n and m, find the n-th root of m. The n-th root of m is an integer x such that x^n = m. If no such integer exists, return -1.

Examples: 

Input: n = 3, m = 27
Output: 3
Explanation: 33 = 27

Input: n = 3, m = 9
Output: -1
Explanation: 3rd root of 9 is not integer.*/ 
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    // helper function to calculate mid^n
    int power(int mid, int n, int m) {
        long long ans = 1;
        for (int i = 1; i <= n; i++) {
            ans *= mid;
            if (ans > m) return 2; // exceeded m
        }
        if (ans == m) return 1;   // exact match
        return 0;                 // less than m
    }

    int nthRoot(int n, int m) {
        int low = 1, high = m;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int val = power(mid, n, m);

            if (val == 1)
                return mid;
            else if (val == 2)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1; // no integer nth root
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Solution obj;
    cout << obj.nthRoot(n, m) << endl;

    return 0;
}
