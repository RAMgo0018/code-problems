/*Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:

Input: piles = [3,6,7,11], h = 8
Output: 4*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double helper(vector<int>& piles, int t) {
        int n = piles.size();
        double totalhours = 0;
        for (int i = 0; i < n; i++) {
            totalhours += ceil((double)piles[i] / (double)t);
        }
        return totalhours;
    }

    int maxelement(vector<int>& piles) {
        int maxi = 0;
        for (int x : piles) maxi = max(maxi, x);
        return maxi;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = maxelement(piles);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            double totalhours = helper(piles, mid);

            if (totalhours <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> piles(n);
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    int h;
    cin >> h;

    Solution obj;
    cout << obj.minEatingSpeed(piles, h) << endl;

    return 0;
}
