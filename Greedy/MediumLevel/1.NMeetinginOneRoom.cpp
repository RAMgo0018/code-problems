/*You are given timings of n meetings in the form of (start[i], end[i]) where start[i] is the start time of meeting i and end[i] is the finish time of meeting i. Return the maximum number of meetings that can be accommodated in a single meeting room, when only one meeting can be held in the meeting room at a particular time. 

Note: The start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

Examples :

Input: start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
Output: 4
Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5,7) and (8,9)*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct coll {
        int start = 0;
        int end = 0;
        int pos = 0;
    };

    // Comparator to sort by end time
    static bool cmp(const coll &a, const coll &b) {
        return a.end < b.end;
    }

    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<coll> arr(n);

        // Fill arr
        for (int i = 0; i < n; i++) {
            arr[i].start = start[i];
            arr[i].end = end[i];
            arr[i].pos = i + 1;
        }

        sort(arr.begin(), arr.end(), cmp);

        int count = 1;
        int EndTime = arr[0].end;

        for (int i = 1; i < n; i++) {
            if (arr[i].start > EndTime) {
                count++;
                EndTime = arr[i].end;
            }
        }

        return count;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> start(n), end(n);

    for (int i = 0; i < n; i++) {
        cin >> start[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> end[i];
    }

    Solution obj;
    cout << obj.maxMeetings(start, end);

    return 0;
}
