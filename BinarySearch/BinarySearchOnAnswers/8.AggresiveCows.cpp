/*You are given an array with unique elements of stalls[], which denote the positions of stalls. You are also given an integer k which denotes the number of aggressive cows. The task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

Examples:

Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows in this case is 3, which is the largest among all possible ways.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool canplace(vector<int> &stalls, int distance, int k)
    {
        int currentcows = 1;
        int last = stalls[0];
        for (int i = 1; i < stalls.size(); i++)
        {
            if (stalls[i] - last >= distance)
            {
                last = stalls[i];
                currentcows++;
            }
            else
                continue;
        }
        if (currentcows >= k)
            return true;
        else
            return false;
    }

public:
    int aggressiveCows(vector<int> &stalls, int k)
    {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        int low = 1;
        int high = stalls[n - 1] - stalls[0];
        int ans = 0;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (canplace(stalls, mid, k) == true)
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> stalls(n);
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    int k;
    cin >> k;

    Solution obj;
    cout << obj.aggressiveCows(stalls, k) << endl;

    return 0;
}
