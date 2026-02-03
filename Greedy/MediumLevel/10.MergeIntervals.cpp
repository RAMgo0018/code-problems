/*Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergeIntervals;
        if(intervals.size() == 0)
            return mergeIntervals;

        sort(intervals.begin(), intervals.end()); // sort by start times
        vector<int> temp = intervals[0];

        for(auto it : intervals) {
            if(temp[1] >= it[0]) {
                // Overlapping intervals, merge them
                temp[1] = max(temp[1], it[1]);
            } else {
                mergeIntervals.push_back(temp);
                temp = it;
            }
        }

        mergeIntervals.push_back(temp);
        return mergeIntervals;
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
    vector<vector<int>> result = obj.merge(intervals);

    cout << "Merged Intervals:\n";
    for(auto it : result) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << "\n";

    return 0;
}
