/*Given arrival arr[] and departure dep[] times of trains on the same day, find the minimum number of platforms needed so that no train waits. A platform cannot serve two trains at the same time; if a train arrives before another departs, an extra platform is needed.

Note: Time intervals are in the 24-hour format (HHMM) , where the first two characters represent hour (between 00 to 23 ) and the last two characters represent minutes (this will be <= 59 and >= 0). Leading zeros for hours less than 10 are optional (e.g., 0900 is the same as 900).

Examples:

Input: arr[] = [900, 940, 950, 1100, 1500, 1800], dep[] = [910, 1200, 1120, 1130, 1900, 2000]
Output: 3
Explanation: There are three trains during the time 9:40 to 12:00. So we need a minimum of 3 platforms*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int i = 0, j = 0;
        int count = 0;
        int maxcount = 0;
        int n = arr.size();

        while(i < n && j < n) {
            if(arr[i] <= dep[j]) {   // train arrives
                count++;
                i++;
            } else {                // train departs
                count--;
                j++;
            }
            maxcount = max(maxcount, count);
        }
        return maxcount;
    }
};

int main() {
    int n;
    cin >> n; // number of trains

    vector<int> arr(n), dep(n);

    // arrival times
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // departure times
    for(int i = 0; i < n; i++) {
        cin >> dep[i];
    }

    Solution obj;
    cout << obj.minPlatform(arr, dep) << endl;

    return 0;
}
