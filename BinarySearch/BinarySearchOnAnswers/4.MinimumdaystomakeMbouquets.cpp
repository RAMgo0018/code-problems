/*You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

 

Example 1:

Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
We need 3 bouquets each should contain 1 flower.
After day 1: [x, _, _, _, _]   // we can only make one bouquet.
After day 2: [x, _, _, _, x]   // we can only make two bouquets.
After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool func(vector<int>& arr, int m, int k, int days) {
        int count = 0, bouquet = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= days) {
                count++;
                if (count == k) {
                    bouquet++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        return bouquet >= m;
    }

    int minDays(vector<int>& arr, int m, int k) {
        if ((long long)m * k > (long long)arr.size()) return -1;

        int s = *min_element(arr.begin(), arr.end());
        int e = *max_element(arr.begin(), arr.end());
        int mindays = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (func(arr, m, k, mid)) {
                mindays = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return mindays;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int m, k;
    cin >> m >> k;

    Solution obj;
    cout << obj.minDays(arr, m, k) << endl;

    return 0;
}
