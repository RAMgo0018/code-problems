/*You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) return 1;

        int prev2 = 1; // f(0)
        int prev = 1;  // f(1)

        for (int i = 2; i <= n; i++) {
            int curr = prev + prev2;
            prev2 = prev;   // shift
            prev = curr;    // shift
        }

        return prev;
    }
};

int main() {
    int n;
    cin >> n;

    Solution obj;
    cout << obj.climbStairs(n);

    return 0;
}
