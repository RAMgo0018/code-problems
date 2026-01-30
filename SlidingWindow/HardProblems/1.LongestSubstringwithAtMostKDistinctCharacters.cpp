/*
Longest Substring with K Uniques
Difficulty: MediumAccuracy: 34.65%Submissions: 259K+Points: 4
You are given a string s consisting only lowercase alphabets and an integer k. Your task is to find the length of the longest substring that contains exactly k distinct characters.

Note : If no such substring exists, return -1. 

Examples:

Input: s = "aabacbebebe", k = 3
Output: 7
Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.
Input: s = "aaaa", k = 2
Output: -1
Explanation: There's no substring with 2 distinct characters.
Input: s = "aabaaab", k = 2
Output: 7
Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b', making it the longest valid substring.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int l = 0, r = 0;
        int maxlength = -1; // default -1 if no valid substring
        unordered_map<char,int> mp;
        int n = s.size();

        while (r < n) {
            mp[s[r]]++;

            // shrink window if distinct chars > k
            while (mp.size() > k) {
                mp[s[l]]--;
                if (mp[s[l]] == 0)
                    mp.erase(s[l]);
                l++;
            }

            // update only if window has exactly k distinct chars
            if (mp.size() == k) {
                int length = r - l + 1;
                maxlength = max(maxlength, length);
            }

            r++;
        }
        return maxlength;
    }
};

int main() {
    string s;
    cin >> s;

    int k;
    cin >> k;

    Solution obj;
    cout << obj.longestKSubstr(s, k);

    return 0;
}
