/*You are given two arrays: deadline[], and profit[], which represent a set of jobs, where each job is associated with a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.

Your task is to find:

The maximum number of jobs that can be completed within their deadlines.
The total maximum profit earned by completing those jobs.
Examples :

Input: deadline[] = [4, 1, 1, 1], profit[] = [20, 10, 40, 30]
Output: [2, 60]
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct item {
        int id;
        int deadline;
        int profit;
    };

    // Sort jobs by profit in descending order
    static bool cmp(item a, item b) {
        return a.profit > b.profit;
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = profit.size();
        vector<item> items(n);

        for(int i = 0; i < n; i++) {
            items[i].id = i;
            items[i].deadline = deadline[i];
            items[i].profit = profit[i];
        }

        sort(items.begin(), items.end(), cmp);

        int maxDeadline = 0;
        for(int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, items[i].deadline);
        }

        vector<int> slot(maxDeadline + 1, -1);

        int count = 0;
        long long totalProfit = 0;

        for(int i = 0; i < n; i++) {
            for(int j = items[i].deadline; j > 0; j--) {
                if(slot[j] == -1) {
                    slot[j] = items[i].id;
                    count++;
                    totalProfit += items[i].profit;
                    break;
                }
            }
        }

        return {count, (int)totalProfit};
    }
};

int main() {
    int n;
    cin >> n; // number of jobs

    vector<int> deadline(n), profit(n);
    for(int i = 0; i < n; i++) {
        cin >> deadline[i]; // deadlines
    }
    for(int i = 0; i < n; i++) {
        cin >> profit[i]; // profits
    }

    Solution obj;
    vector<int> result = obj.jobSequencing(deadline, profit);

    cout << "Maximum jobs: " << result[0] << "\n";
    cout << "Total profit: " << result[1] << "\n";

    return 0;
}
