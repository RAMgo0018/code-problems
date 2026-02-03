/*You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        int i = 0;

        // 1. Add all intervals before newInterval
        while(i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }

        // 2. Merge overlapping intervals
        while(i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        res.push_back(newInterval);

        // 3. Add remaining intervals
        while(i < n) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};

int main() {
    int n;
    cin >> n; // number of existing intervals

    vector<vector<int>> intervals(n, vector<int>(2));
    for(int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    vector<int> newInterval(2);
    cin >> newInterval[0] >> newInterval[1];

    Solution obj;
    vector<vector<int>> result = obj.insert(intervals, newInterval);

    cout << "Intervals after insertion:\n";
    for(auto it : result) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << "\n";

    return 0;
}
