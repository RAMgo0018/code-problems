/*Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Comparator to sort intervals by end time
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), cmp);

        int endtime = intervals[0][1];
        int count = 0;

        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] >= endtime) {
                endtime = intervals[i][1];
            } else {
                count++; // overlapping interval → remove
            }
        }

        return count;
    }
};

int main() {
    int n;
    cin >> n; // number of intervals

    vector<vector<int>> intervals(n, vector<int>(2));
    for(int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1]; // input start and end
    }

    Solution obj;
    int result = obj.eraseOverlapIntervals(intervals);

    cout << "Number of intervals to remove: " << result << "\n";

    return 0;
}
