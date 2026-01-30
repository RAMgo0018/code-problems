/*Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int l = 0, r = 0;
        int sindex = -1;
        int minlength = INT_MAX;
        int count = 0;
        vector<int> hash(256, 0);

        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }

        while (r < n) {
            hash[s[r]]--;
            if (hash[s[r]] >= 0) {
                count++;
            }

            while (count == m) {
                if (r - l + 1 < minlength) {
                    minlength = r - l + 1;
                    sindex = l;
                }

                hash[s[l]]++;
                if (hash[s[l]] > 0)
                    count--;
                l++;
            }

            r++;
        }

        return sindex == -1 ? "" : s.substr(sindex, minlength);
    }
};

int main() {
    string s, t;
    cin >> s >> t;

    Solution obj;
    string ans = obj.minWindow(s, t);
    if (ans == "")
        cout << "No valid window found";
    else
        cout << ans;

    return 0;
}
