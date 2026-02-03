/*Geek is a software engineer. He is assigned with the task of calculating average waiting time of all the processes by following shortest job first policy.

The shortest job first (SJF) or shortest job next, is a scheduling policy that selects the waiting process with the smallest execution time to execute next.

Given an array of integers bt of size n. Array bt denotes the burst time of each process. Calculate the average waiting time of all the processes and return the nearest integer which is smaller or equal to the output.

Note: Consider all process are available at time 0.

Example 1:

Input:
n = 5
bt = [4,3,7,1,2]
Output: 4*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(vector<int>& bt) {
        int n = bt.size();
        
        // Step 1: sort burst times (SJF rule)
        sort(bt.begin(), bt.end());
        
        long long totalwaiting = 0;
        long long waitingtime = 0;
        
        // Step 2: calculate waiting time
        for(int i = 0; i < n - 1; i++) {
            waitingtime += bt[i];
            totalwaiting += waitingtime;
        }
        
        // Step 3: return average waiting time
        return totalwaiting / n;
    }
};

int main() {
    int n;
    cin >> n; // number of processes

    vector<int> bt(n);
    for(int i = 0; i < n; i++) {
        cin >> bt[i]; // burst times
    }

    Solution obj;
    cout << obj.solve(bt) << "\n";

    return 0;
}
