/*You are given an array arr of positive integers. Your task is to find all the leaders in the array. An element is considered a leader if it is greater than or equal to all elements to its right. The rightmost element is always a leader.

Examples:

Input: arr = [16, 17, 4, 3, 5, 2]
Output: [17, 5, 2]
Explanation: Note that there is nothing greater on the right side of 17, 5 and, 2.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leaders(vector<int>& arr) 
    { 
        /* Brute force (commented)
        vector<int> leaders;
        int n=arr.size();
        for(int i=0;i<n;i++)
        { 
            bool flag=true;
            for(int j=i+1;j<n;j++)
            {
                if(arr[j]>arr[i]){
                    flag=false;
                    break;
                }
            }
            if(flag==true)
                leaders.push_back(arr[i]);
        }
        return leaders;
        */

        vector<int> leaders;
        int n=arr.size();
        int currl=arr[n-1];
        leaders.push_back(arr[n-1]);
        for(int i=n-2;i>=0;i--)//Traversing from back if a number is greater than current leader than it  is also a leader
        {
            if(arr[i]>=currl)
            {
                currl=arr[i];
                leaders.push_back(arr[i]);
            }
        }
        reverse(leaders.begin(),leaders.end());
        return leaders;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> ans = sol.leaders(arr);

    cout << "Leaders in the array: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
