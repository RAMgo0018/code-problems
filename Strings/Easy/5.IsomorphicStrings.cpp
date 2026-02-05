/*Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"

Output: true

Explanation:

The strings s and t can be made identical by:

Mapping 'e' to 'a'.
Mapping 'g' to 'd'.*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) return "";

        sort(strs.begin(), strs.end());

        string result = "";
        string first = strs[0];
        string last = strs[n - 1];

        for (int i = 0; i < first.length() && i < last.length(); i++) {
            if (first[i] == last[i]) {
                result += first[i];
            } else {
                break;
            }
        }
        return result;
    }
};

int main() {
    int n;
    cin >> n;  // number of strings
    vector<string> strs(n);

    for(int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    Solution obj;
    string lcp = obj.longestCommonPrefix(strs);

    if(lcp.empty())
        cout << "No common prefix";
    else
        cout << "Longest Common Prefix: " << lcp;

    return 0;
}
