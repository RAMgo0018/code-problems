/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"*/
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
/* BRUTE FORCE SOLUTION
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string ans="";
        string first=strs[0];
        int m=first.length();
        for(int i=0;i<m;i++)
        {
            char c=first[i];
            for(int j=1;j<n;j++)
            {
                if(i>strs[j].length()||strs[j][i]!=c)
                return ans;
            }
            ans+=c;
        }
        return ans;
        
    }
};*/
